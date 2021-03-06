/**
 * Vericred API
 * Vericred's API allows you to search for Health Plans that a specific doctor
accepts.

## Getting Started

Visit our [Developer Portal](https://developers.vericred.com) to
create an account.

Once you have created an account, you can create one Application for
Production and another for our Sandbox (select the appropriate Plan when
you create the Application).

## SDKs

Our API follows standard REST conventions, so you can use any HTTP client
to integrate with us. You will likely find it easier to use one of our
[autogenerated SDKs](https://github.com/vericred/?query=vericred-),
which we make available for several common programming languages.

## Authentication

To authenticate, pass the API Key you created in the Developer Portal as
a `Vericred-Api-Key` header.

`curl -H 'Vericred-Api-Key: YOUR_KEY' "https://api.vericred.com/providers?search_term=Foo&zip_code=11215"`

## Versioning

Vericred's API default to the latest version.  However, if you need a specific
version, you can request it with an `Accept-Version` header.

The current version is `v3`.  Previous versions are `v1` and `v2`.

`curl -H 'Vericred-Api-Key: YOUR_KEY' -H 'Accept-Version: v2' "https://api.vericred.com/providers?search_term=Foo&zip_code=11215"`

## Pagination

Endpoints that accept `page` and `per_page` parameters are paginated. They expose
four additional fields that contain data about your position in the response,
namely `Total`, `Per-Page`, `Link`, and `Page` as described in [RFC-5988](https://tools.ietf.org/html/rfc5988).

For example, to display 5 results per page and view the second page of a
`GET` to `/networks`, your final request would be `GET /networks?....page=2&per_page=5`.

## Sideloading

When we return multiple levels of an object graph (e.g. `Provider`s and their `State`s
we sideload the associated data.  In this example, we would provide an Array of
`State`s and a `state_id` for each provider.  This is done primarily to reduce the
payload size since many of the `Provider`s will share a `State`

```
{
  providers: [{ id: 1, state_id: 1}, { id: 2, state_id: 1 }],
  states: [{ id: 1, code: 'NY' }]
}
```

If you need the second level of the object graph, you can just match the
corresponding id.

## Selecting specific data

All endpoints allow you to specify which fields you would like to return.
This allows you to limit the response to contain only the data you need.

For example, let's take a request that returns the following JSON by default

```
{
  provider: {
    id: 1,
    name: 'John',
    phone: '1234567890',
    field_we_dont_care_about: 'value_we_dont_care_about'
  },
  states: [{
    id: 1,
    name: 'New York',
    code: 'NY',
    field_we_dont_care_about: 'value_we_dont_care_about'
  }]
}
```

To limit our results to only return the fields we care about, we specify the
`select` query string parameter for the corresponding fields in the JSON
document.

In this case, we want to select `name` and `phone` from the `provider` key,
so we would add the parameters `select=provider.name,provider.phone`.
We also want the `name` and `code` from the `states` key, so we would
add the parameters `select=states.name,staes.code`.  The id field of
each document is always returned whether or not it is requested.

Our final request would be `GET /providers/12345?select=provider.name,provider.phone,states.name,states.code`

The response would be

```
{
  provider: {
    id: 1,
    name: 'John',
    phone: '1234567890'
  },
  states: [{
    id: 1,
    name: 'New York',
    code: 'NY'
  }]
}
```

## Benefits summary format
Benefit cost-share strings are formatted to capture:
 * Network tiers
 * Compound or conditional cost-share
 * Limits on the cost-share
 * Benefit-specific maximum out-of-pocket costs

**Example #1**
As an example, we would represent [this Summary of Benefits &amp; Coverage](https://s3.amazonaws.com/vericred-data/SBC/2017/33602TX0780032.pdf) as:

* **Hospital stay facility fees**:
  - Network Provider: `$400 copay/admit plus 20% coinsurance`
  - Out-of-Network Provider: `$1,500 copay/admit plus 50% coinsurance`
  - Vericred's format for this benefit: `In-Network: $400 before deductible then 20% after deductible / Out-of-Network: $1,500 before deductible then 50% after deductible`

* **Rehabilitation services:**
  - Network Provider: `20% coinsurance`
  - Out-of-Network Provider: `50% coinsurance`
  - Limitations & Exceptions: `35 visit maximum per benefit period combined with Chiropractic care.`
  - Vericred's format for this benefit: `In-Network: 20% after deductible / Out-of-Network: 50% after deductible | limit: 35 visit(s) per Benefit Period`

**Example #2**
In [this other Summary of Benefits &amp; Coverage](https://s3.amazonaws.com/vericred-data/SBC/2017/40733CA0110568.pdf), the **specialty_drugs** cost-share has a maximum out-of-pocket for in-network pharmacies.
* **Specialty drugs:**
  - Network Provider: `40% coinsurance up to a $500 maximum for up to a 30 day supply`
  - Out-of-Network Provider `Not covered`
  - Vericred's format for this benefit: `In-Network: 40% after deductible, up to $500 per script / Out-of-Network: 100%`

**BNF**

Here's a description of the benefits summary string, represented as a context-free grammar:

```
<cost-share>     ::= <tier> <opt-num-prefix> <value> <opt-per-unit> <deductible> <tier-limit> "/" <tier> <opt-num-prefix> <value> <opt-per-unit> <deductible> "|" <benefit-limit>
<tier>           ::= "In-Network:" | "In-Network-Tier-2:" | "Out-of-Network:"
<opt-num-prefix> ::= "first" <num> <unit> | ""
<unit>           ::= "day(s)" | "visit(s)" | "exam(s)" | "item(s)"
<value>          ::= <ddct_moop> | <copay> | <coinsurance> | <compound> | "unknown" | "Not Applicable"
<compound>       ::= <copay> <deductible> "then" <coinsurance> <deductible> | <copay> <deductible> "then" <copay> <deductible> | <coinsurance> <deductible> "then" <coinsurance> <deductible>
<copay>          ::= "$" <num>
<coinsurace>     ::= <num> "%"
<ddct_moop>      ::= <copay> | "Included in Medical" | "Unlimited"
<opt-per-unit>   ::= "per day" | "per visit" | "per stay" | ""
<deductible>     ::= "before deductible" | "after deductible" | ""
<tier-limit>     ::= ", " <limit> | ""
<benefit-limit>  ::= <limit> | ""
```


 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "SWGRequestPlanFind.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGRequestPlanFind::SWGRequestPlanFind(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRequestPlanFind::SWGRequestPlanFind() {
    init();
}

SWGRequestPlanFind::~SWGRequestPlanFind() {
    this->cleanup();
}

void
SWGRequestPlanFind::init() {
    applicants = new QList<SWGRequestPlanFindApplicant*>();
enrollment_date = new QString("");
drug_packages = new QList<SWGRequestPlanFindDrugPackage*>();
fips_code = new QString("");
household_income = 0;
household_size = 0;
ids = new QList<qint32>();
market = new QString("");
providers = new QList<SWGRequestPlanFindProvider*>();
page = 0;
per_page = 0;
sort = new QString("");
zip_code = new QString("");
}

void
SWGRequestPlanFind::cleanup() {
    if(applicants != NULL) {
        QList<SWGRequestPlanFindApplicant*>* arr = applicants;
        foreach(SWGRequestPlanFindApplicant* o, *arr) {
            delete o;
        }
        delete applicants;
    }
if(enrollment_date != NULL) {
        delete enrollment_date;
    }
if(drug_packages != NULL) {
        QList<SWGRequestPlanFindDrugPackage*>* arr = drug_packages;
        foreach(SWGRequestPlanFindDrugPackage* o, *arr) {
            delete o;
        }
        delete drug_packages;
    }
if(fips_code != NULL) {
        delete fips_code;
    }



if(market != NULL) {
        delete market;
    }
if(providers != NULL) {
        QList<SWGRequestPlanFindProvider*>* arr = providers;
        foreach(SWGRequestPlanFindProvider* o, *arr) {
            delete o;
        }
        delete providers;
    }


if(sort != NULL) {
        delete sort;
    }
if(zip_code != NULL) {
        delete zip_code;
    }
}

SWGRequestPlanFind*
SWGRequestPlanFind::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRequestPlanFind::fromJsonObject(QJsonObject &pJson) {
    setValue(&applicants, pJson["applicants"], "QList", "SWGRequestPlanFindApplicant");
setValue(&enrollment_date, pJson["enrollment_date"], "QString", "QString");
setValue(&drug_packages, pJson["drug_packages"], "QList", "SWGRequestPlanFindDrugPackage");
setValue(&fips_code, pJson["fips_code"], "QString", "QString");
setValue(&household_income, pJson["household_income"], "qint32", "");
setValue(&household_size, pJson["household_size"], "qint32", "");
setValue(&ids, pJson["ids"], "QList", "");
setValue(&market, pJson["market"], "QString", "QString");
setValue(&providers, pJson["providers"], "QList", "SWGRequestPlanFindProvider");
setValue(&page, pJson["page"], "qint32", "");
setValue(&per_page, pJson["per_page"], "qint32", "");
setValue(&sort, pJson["sort"], "QString", "QString");
setValue(&zip_code, pJson["zip_code"], "QString", "QString");
}

QString
SWGRequestPlanFind::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGRequestPlanFind::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    QList<SWGRequestPlanFindApplicant*>* applicantsList = applicants;
    QJsonArray applicantsJsonArray;
    toJsonArray((QList<void*>*)applicants, &applicantsJsonArray, "applicants", "SWGRequestPlanFindApplicant");

    obj->insert("applicants", applicantsJsonArray);
    

    
    toJsonValue(QString("enrollment_date"), enrollment_date, obj, QString("QString"));
    
        

    
    QList<SWGRequestPlanFindDrugPackage*>* drug_packagesList = drug_packages;
    QJsonArray drug_packagesJsonArray;
    toJsonArray((QList<void*>*)drug_packages, &drug_packagesJsonArray, "drug_packages", "SWGRequestPlanFindDrugPackage");

    obj->insert("drug_packages", drug_packagesJsonArray);
    

    
    toJsonValue(QString("fips_code"), fips_code, obj, QString("QString"));
    
        
obj->insert("household_income", QJsonValue(household_income));
obj->insert("household_size", QJsonValue(household_size));
obj->insert("ids", QJsonValue(ids));

    
    toJsonValue(QString("market"), market, obj, QString("QString"));
    
        

    
    QList<SWGRequestPlanFindProvider*>* providersList = providers;
    QJsonArray providersJsonArray;
    toJsonArray((QList<void*>*)providers, &providersJsonArray, "providers", "SWGRequestPlanFindProvider");

    obj->insert("providers", providersJsonArray);
    
obj->insert("page", QJsonValue(page));
obj->insert("per_page", QJsonValue(per_page));

    
    toJsonValue(QString("sort"), sort, obj, QString("QString"));
    
        

    
    toJsonValue(QString("zip_code"), zip_code, obj, QString("QString"));
    
        

    return obj;
}

QList<SWGRequestPlanFindApplicant*>*
SWGRequestPlanFind::getApplicants() {
    return applicants;
}
void
SWGRequestPlanFind::setApplicants(QList<SWGRequestPlanFindApplicant*>* applicants) {
    this->applicants = applicants;
}

QString*
SWGRequestPlanFind::getEnrollmentDate() {
    return enrollment_date;
}
void
SWGRequestPlanFind::setEnrollmentDate(QString* enrollment_date) {
    this->enrollment_date = enrollment_date;
}

QList<SWGRequestPlanFindDrugPackage*>*
SWGRequestPlanFind::getDrugPackages() {
    return drug_packages;
}
void
SWGRequestPlanFind::setDrugPackages(QList<SWGRequestPlanFindDrugPackage*>* drug_packages) {
    this->drug_packages = drug_packages;
}

QString*
SWGRequestPlanFind::getFipsCode() {
    return fips_code;
}
void
SWGRequestPlanFind::setFipsCode(QString* fips_code) {
    this->fips_code = fips_code;
}

qint32
SWGRequestPlanFind::getHouseholdIncome() {
    return household_income;
}
void
SWGRequestPlanFind::setHouseholdIncome(qint32 household_income) {
    this->household_income = household_income;
}

qint32
SWGRequestPlanFind::getHouseholdSize() {
    return household_size;
}
void
SWGRequestPlanFind::setHouseholdSize(qint32 household_size) {
    this->household_size = household_size;
}

QList<qint32>*
SWGRequestPlanFind::getIds() {
    return ids;
}
void
SWGRequestPlanFind::setIds(QList<qint32>* ids) {
    this->ids = ids;
}

QString*
SWGRequestPlanFind::getMarket() {
    return market;
}
void
SWGRequestPlanFind::setMarket(QString* market) {
    this->market = market;
}

QList<SWGRequestPlanFindProvider*>*
SWGRequestPlanFind::getProviders() {
    return providers;
}
void
SWGRequestPlanFind::setProviders(QList<SWGRequestPlanFindProvider*>* providers) {
    this->providers = providers;
}

qint32
SWGRequestPlanFind::getPage() {
    return page;
}
void
SWGRequestPlanFind::setPage(qint32 page) {
    this->page = page;
}

qint32
SWGRequestPlanFind::getPerPage() {
    return per_page;
}
void
SWGRequestPlanFind::setPerPage(qint32 per_page) {
    this->per_page = per_page;
}

QString*
SWGRequestPlanFind::getSort() {
    return sort;
}
void
SWGRequestPlanFind::setSort(QString* sort) {
    this->sort = sort;
}

QString*
SWGRequestPlanFind::getZipCode() {
    return zip_code;
}
void
SWGRequestPlanFind::setZipCode(QString* zip_code) {
    this->zip_code = zip_code;
}



} /* namespace Swagger */

