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


#include "SWGDrugCoverage.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGDrugCoverage::SWGDrugCoverage(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDrugCoverage::SWGDrugCoverage() {
    init();
}

SWGDrugCoverage::~SWGDrugCoverage() {
    this->cleanup();
}

void
SWGDrugCoverage::init() {
    plan_id = new QString("");
drug_package_id = new QString("");
med_id = 0;
quantity_limit = false;
prior_authorization = false;
step_therapy = false;
tier = new QString("");
}

void
SWGDrugCoverage::cleanup() {
    if(plan_id != NULL) {
        delete plan_id;
    }
if(drug_package_id != NULL) {
        delete drug_package_id;
    }




if(tier != NULL) {
        delete tier;
    }
}

SWGDrugCoverage*
SWGDrugCoverage::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDrugCoverage::fromJsonObject(QJsonObject &pJson) {
    setValue(&plan_id, pJson["plan_id"], "QString", "QString");
setValue(&drug_package_id, pJson["drug_package_id"], "QString", "QString");
setValue(&med_id, pJson["med_id"], "qint32", "");
setValue(&quantity_limit, pJson["quantity_limit"], "bool", "");
setValue(&prior_authorization, pJson["prior_authorization"], "bool", "");
setValue(&step_therapy, pJson["step_therapy"], "bool", "");
setValue(&tier, pJson["tier"], "QString", "QString");
}

QString
SWGDrugCoverage::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGDrugCoverage::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("plan_id"), plan_id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("drug_package_id"), drug_package_id, obj, QString("QString"));
    
        
obj->insert("med_id", QJsonValue(med_id));
obj->insert("quantity_limit", QJsonValue(quantity_limit));
obj->insert("prior_authorization", QJsonValue(prior_authorization));
obj->insert("step_therapy", QJsonValue(step_therapy));

    
    toJsonValue(QString("tier"), tier, obj, QString("QString"));
    
        

    return obj;
}

QString*
SWGDrugCoverage::getPlanId() {
    return plan_id;
}
void
SWGDrugCoverage::setPlanId(QString* plan_id) {
    this->plan_id = plan_id;
}

QString*
SWGDrugCoverage::getDrugPackageId() {
    return drug_package_id;
}
void
SWGDrugCoverage::setDrugPackageId(QString* drug_package_id) {
    this->drug_package_id = drug_package_id;
}

qint32
SWGDrugCoverage::getMedId() {
    return med_id;
}
void
SWGDrugCoverage::setMedId(qint32 med_id) {
    this->med_id = med_id;
}

bool
SWGDrugCoverage::getQuantityLimit() {
    return quantity_limit;
}
void
SWGDrugCoverage::setQuantityLimit(bool quantity_limit) {
    this->quantity_limit = quantity_limit;
}

bool
SWGDrugCoverage::getPriorAuthorization() {
    return prior_authorization;
}
void
SWGDrugCoverage::setPriorAuthorization(bool prior_authorization) {
    this->prior_authorization = prior_authorization;
}

bool
SWGDrugCoverage::getStepTherapy() {
    return step_therapy;
}
void
SWGDrugCoverage::setStepTherapy(bool step_therapy) {
    this->step_therapy = step_therapy;
}

QString*
SWGDrugCoverage::getTier() {
    return tier;
}
void
SWGDrugCoverage::setTier(QString* tier) {
    this->tier = tier;
}



} /* namespace Swagger */

