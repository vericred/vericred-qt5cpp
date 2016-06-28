/**
 * Vericred API
 * Vericred's API allows you to search for Health Plans that a specific doctor
accepts.

## Getting Started

Visit our [Developer Portal](https://vericred.3scale.net) to
create an account.

Once you have created an account, you can create one Application for
Production and another for our Sandbox (select the appropriate Plan when
you create the Application).

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


#include "SWGApplicant.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGApplicant::SWGApplicant(QString* json) {
    init();
    this->fromJson(*json);
}

SWGApplicant::SWGApplicant() {
    init();
}

SWGApplicant::~SWGApplicant() {
    this->cleanup();
}

void
SWGApplicant::init() {
    id = NULL;
dob = NULL;
member_id = new QString("");
name = new QString("");
relationship = new QString("");
smoker = false;
ssn = new QString("");
}

void
SWGApplicant::cleanup() {
    
if(dob != NULL) {
        delete dob;
    }
if(member_id != NULL) {
        delete member_id;
    }
if(name != NULL) {
        delete name;
    }
if(relationship != NULL) {
        delete relationship;
    }

if(ssn != NULL) {
        delete ssn;
    }
}

SWGApplicant*
SWGApplicant::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGApplicant::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&dob, pJson["dob"], "QDate", "QDate");
setValue(&member_id, pJson["member_id"], "QString", "QString");
setValue(&name, pJson["name"], "QString", "QString");
setValue(&relationship, pJson["relationship"], "QString", "QString");
setValue(&smoker, pJson["smoker"], "bool", "");
setValue(&ssn, pJson["ssn"], "QString", "QString");
}

QString
SWGApplicant::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGApplicant::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("dob"), dob, obj, QString("QDate"));
    
        

    
    toJsonValue(QString("member_id"), member_id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("relationship"), relationship, obj, QString("QString"));
    
        
obj->insert("smoker", QJsonValue(smoker));

    
    toJsonValue(QString("ssn"), ssn, obj, QString("QString"));
    
        

    return obj;
}

qint32
SWGApplicant::getId() {
    return id;
}
void
SWGApplicant::setId(qint32 id) {
    this->id = id;
}

QDate*
SWGApplicant::getDob() {
    return dob;
}
void
SWGApplicant::setDob(QDate* dob) {
    this->dob = dob;
}

QString*
SWGApplicant::getMemberId() {
    return member_id;
}
void
SWGApplicant::setMemberId(QString* member_id) {
    this->member_id = member_id;
}

QString*
SWGApplicant::getName() {
    return name;
}
void
SWGApplicant::setName(QString* name) {
    this->name = name;
}

QString*
SWGApplicant::getRelationship() {
    return relationship;
}
void
SWGApplicant::setRelationship(QString* relationship) {
    this->relationship = relationship;
}

bool
SWGApplicant::getSmoker() {
    return smoker;
}
void
SWGApplicant::setSmoker(bool smoker) {
    this->smoker = smoker;
}

QString*
SWGApplicant::getSsn() {
    return ssn;
}
void
SWGApplicant::setSsn(QString* ssn) {
    this->ssn = ssn;
}



} /* namespace Swagger */

