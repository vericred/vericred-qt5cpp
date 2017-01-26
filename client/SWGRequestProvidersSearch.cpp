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


#include "SWGRequestProvidersSearch.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGRequestProvidersSearch::SWGRequestProvidersSearch(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRequestProvidersSearch::SWGRequestProvidersSearch() {
    init();
}

SWGRequestProvidersSearch::~SWGRequestProvidersSearch() {
    this->cleanup();
}

void
SWGRequestProvidersSearch::init() {
    accepts_insurance = false;
min_score = 0.0;
network_ids = new QList<qint32>();
page = 0;
per_page = 0;
polygon = 0;
radius = 0;
search_term = new QString("");
sort = new QString("");
sort_seed = 0;
type = new QString("");
zip_code = new QString("");
}

void
SWGRequestProvidersSearch::cleanup() {
    
if(min_score != NULL) {
        delete min_score;
    }





if(search_term != NULL) {
        delete search_term;
    }
if(sort != NULL) {
        delete sort;
    }

if(type != NULL) {
        delete type;
    }
if(zip_code != NULL) {
        delete zip_code;
    }
}

SWGRequestProvidersSearch*
SWGRequestProvidersSearch::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRequestProvidersSearch::fromJsonObject(QJsonObject &pJson) {
    setValue(&accepts_insurance, pJson["accepts_insurance"], "bool", "");
setValue(&min_score, pJson["min_score"], "SWGNumber", "SWGNumber");
setValue(&network_ids, pJson["network_ids"], "QList", "");
setValue(&page, pJson["page"], "qint32", "");
setValue(&per_page, pJson["per_page"], "qint32", "");
setValue(&polygon, pJson["polygon"], "qint32", "");
setValue(&radius, pJson["radius"], "qint32", "");
setValue(&search_term, pJson["search_term"], "QString", "QString");
setValue(&sort, pJson["sort"], "QString", "QString");
setValue(&sort_seed, pJson["sort_seed"], "qint32", "");
setValue(&type, pJson["type"], "QString", "QString");
setValue(&zip_code, pJson["zip_code"], "QString", "QString");
}

QString
SWGRequestProvidersSearch::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGRequestProvidersSearch::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("accepts_insurance", QJsonValue(accepts_insurance));

    
    toJsonValue(QString("min_score"), min_score, obj, QString("SWGNumber"));
    
        
obj->insert("network_ids", QJsonValue(network_ids));
obj->insert("page", QJsonValue(page));
obj->insert("per_page", QJsonValue(per_page));
obj->insert("polygon", QJsonValue(polygon));
obj->insert("radius", QJsonValue(radius));

    
    toJsonValue(QString("search_term"), search_term, obj, QString("QString"));
    
        

    
    toJsonValue(QString("sort"), sort, obj, QString("QString"));
    
        
obj->insert("sort_seed", QJsonValue(sort_seed));

    
    toJsonValue(QString("type"), type, obj, QString("QString"));
    
        

    
    toJsonValue(QString("zip_code"), zip_code, obj, QString("QString"));
    
        

    return obj;
}

bool
SWGRequestProvidersSearch::getAcceptsInsurance() {
    return accepts_insurance;
}
void
SWGRequestProvidersSearch::setAcceptsInsurance(bool accepts_insurance) {
    this->accepts_insurance = accepts_insurance;
}

SWGNumber*
SWGRequestProvidersSearch::getMinScore() {
    return min_score;
}
void
SWGRequestProvidersSearch::setMinScore(SWGNumber* min_score) {
    this->min_score = min_score;
}

QList<qint32>*
SWGRequestProvidersSearch::getNetworkIds() {
    return network_ids;
}
void
SWGRequestProvidersSearch::setNetworkIds(QList<qint32>* network_ids) {
    this->network_ids = network_ids;
}

qint32
SWGRequestProvidersSearch::getPage() {
    return page;
}
void
SWGRequestProvidersSearch::setPage(qint32 page) {
    this->page = page;
}

qint32
SWGRequestProvidersSearch::getPerPage() {
    return per_page;
}
void
SWGRequestProvidersSearch::setPerPage(qint32 per_page) {
    this->per_page = per_page;
}

qint32
SWGRequestProvidersSearch::getPolygon() {
    return polygon;
}
void
SWGRequestProvidersSearch::setPolygon(qint32 polygon) {
    this->polygon = polygon;
}

qint32
SWGRequestProvidersSearch::getRadius() {
    return radius;
}
void
SWGRequestProvidersSearch::setRadius(qint32 radius) {
    this->radius = radius;
}

QString*
SWGRequestProvidersSearch::getSearchTerm() {
    return search_term;
}
void
SWGRequestProvidersSearch::setSearchTerm(QString* search_term) {
    this->search_term = search_term;
}

QString*
SWGRequestProvidersSearch::getSort() {
    return sort;
}
void
SWGRequestProvidersSearch::setSort(QString* sort) {
    this->sort = sort;
}

qint32
SWGRequestProvidersSearch::getSortSeed() {
    return sort_seed;
}
void
SWGRequestProvidersSearch::setSortSeed(qint32 sort_seed) {
    this->sort_seed = sort_seed;
}

QString*
SWGRequestProvidersSearch::getType() {
    return type;
}
void
SWGRequestProvidersSearch::setType(QString* type) {
    this->type = type;
}

QString*
SWGRequestProvidersSearch::getZipCode() {
    return zip_code;
}
void
SWGRequestProvidersSearch::setZipCode(QString* zip_code) {
    this->zip_code = zip_code;
}



} /* namespace Swagger */

