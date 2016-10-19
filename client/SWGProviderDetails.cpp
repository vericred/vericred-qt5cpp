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


#include "SWGProviderDetails.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGProviderDetails::SWGProviderDetails(QString* json) {
    init();
    this->fromJson(*json);
}

SWGProviderDetails::SWGProviderDetails() {
    init();
}

SWGProviderDetails::~SWGProviderDetails() {
    this->cleanup();
}

void
SWGProviderDetails::init() {
    accepting_change_of_payor_patients = false;
accepting_medicaid_patients = false;
accepting_medicare_patients = false;
accepting_private_patients = false;
accepting_referral_patients = false;
city = new QString("");
email = new QString("");
gender = new QString("");
first_name = new QString("");
id = 0;
last_name = new QString("");
latitude = 0.0;
longitude = 0.0;
middle_name = new QString("");
network_ids = new QList<qint32>();
organization_name = new QString("");
personal_phone = new QString("");
phone = new QString("");
presentation_name = new QString("");
specialty = new QString("");
state = new QString("");
state_id = 0;
street_line_1 = new QString("");
street_line_2 = new QString("");
suffix = new QString("");
title = new QString("");
type = new QString("");
zip_code = new QString("");
hios_ids = new QList<QString*>();
}

void
SWGProviderDetails::cleanup() {
    




if(city != NULL) {
        delete city;
    }
if(email != NULL) {
        delete email;
    }
if(gender != NULL) {
        delete gender;
    }
if(first_name != NULL) {
        delete first_name;
    }

if(last_name != NULL) {
        delete last_name;
    }
if(latitude != NULL) {
        delete latitude;
    }
if(longitude != NULL) {
        delete longitude;
    }
if(middle_name != NULL) {
        delete middle_name;
    }

if(organization_name != NULL) {
        delete organization_name;
    }
if(personal_phone != NULL) {
        delete personal_phone;
    }
if(phone != NULL) {
        delete phone;
    }
if(presentation_name != NULL) {
        delete presentation_name;
    }
if(specialty != NULL) {
        delete specialty;
    }
if(state != NULL) {
        delete state;
    }

if(street_line_1 != NULL) {
        delete street_line_1;
    }
if(street_line_2 != NULL) {
        delete street_line_2;
    }
if(suffix != NULL) {
        delete suffix;
    }
if(title != NULL) {
        delete title;
    }
if(type != NULL) {
        delete type;
    }
if(zip_code != NULL) {
        delete zip_code;
    }
if(hios_ids != NULL) {
        QList<QString*>* arr = hios_ids;
        foreach(QString* o, *arr) {
            delete o;
        }
        delete hios_ids;
    }
}

SWGProviderDetails*
SWGProviderDetails::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGProviderDetails::fromJsonObject(QJsonObject &pJson) {
    setValue(&accepting_change_of_payor_patients, pJson["accepting_change_of_payor_patients"], "bool", "");
setValue(&accepting_medicaid_patients, pJson["accepting_medicaid_patients"], "bool", "");
setValue(&accepting_medicare_patients, pJson["accepting_medicare_patients"], "bool", "");
setValue(&accepting_private_patients, pJson["accepting_private_patients"], "bool", "");
setValue(&accepting_referral_patients, pJson["accepting_referral_patients"], "bool", "");
setValue(&city, pJson["city"], "QString", "QString");
setValue(&email, pJson["email"], "QString", "QString");
setValue(&gender, pJson["gender"], "QString", "QString");
setValue(&first_name, pJson["first_name"], "QString", "QString");
setValue(&id, pJson["id"], "qint32", "");
setValue(&last_name, pJson["last_name"], "QString", "QString");
setValue(&latitude, pJson["latitude"], "SWGNumber", "SWGNumber");
setValue(&longitude, pJson["longitude"], "SWGNumber", "SWGNumber");
setValue(&middle_name, pJson["middle_name"], "QString", "QString");
setValue(&network_ids, pJson["network_ids"], "QList", "");
setValue(&organization_name, pJson["organization_name"], "QString", "QString");
setValue(&personal_phone, pJson["personal_phone"], "QString", "QString");
setValue(&phone, pJson["phone"], "QString", "QString");
setValue(&presentation_name, pJson["presentation_name"], "QString", "QString");
setValue(&specialty, pJson["specialty"], "QString", "QString");
setValue(&state, pJson["state"], "QString", "QString");
setValue(&state_id, pJson["state_id"], "qint32", "");
setValue(&street_line_1, pJson["street_line_1"], "QString", "QString");
setValue(&street_line_2, pJson["street_line_2"], "QString", "QString");
setValue(&suffix, pJson["suffix"], "QString", "QString");
setValue(&title, pJson["title"], "QString", "QString");
setValue(&type, pJson["type"], "QString", "QString");
setValue(&zip_code, pJson["zip_code"], "QString", "QString");
setValue(&hios_ids, pJson["hios_ids"], "QList", "QString");
}

QString
SWGProviderDetails::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGProviderDetails::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("accepting_change_of_payor_patients", QJsonValue(accepting_change_of_payor_patients));
obj->insert("accepting_medicaid_patients", QJsonValue(accepting_medicaid_patients));
obj->insert("accepting_medicare_patients", QJsonValue(accepting_medicare_patients));
obj->insert("accepting_private_patients", QJsonValue(accepting_private_patients));
obj->insert("accepting_referral_patients", QJsonValue(accepting_referral_patients));

    
    toJsonValue(QString("city"), city, obj, QString("QString"));
    
        

    
    toJsonValue(QString("email"), email, obj, QString("QString"));
    
        

    
    toJsonValue(QString("gender"), gender, obj, QString("QString"));
    
        

    
    toJsonValue(QString("first_name"), first_name, obj, QString("QString"));
    
        
obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("last_name"), last_name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("latitude"), latitude, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("longitude"), longitude, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("middle_name"), middle_name, obj, QString("QString"));
    
        
obj->insert("network_ids", QJsonValue(network_ids));

    
    toJsonValue(QString("organization_name"), organization_name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("personal_phone"), personal_phone, obj, QString("QString"));
    
        

    
    toJsonValue(QString("phone"), phone, obj, QString("QString"));
    
        

    
    toJsonValue(QString("presentation_name"), presentation_name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("specialty"), specialty, obj, QString("QString"));
    
        

    
    toJsonValue(QString("state"), state, obj, QString("QString"));
    
        
obj->insert("state_id", QJsonValue(state_id));

    
    toJsonValue(QString("street_line_1"), street_line_1, obj, QString("QString"));
    
        

    
    toJsonValue(QString("street_line_2"), street_line_2, obj, QString("QString"));
    
        

    
    toJsonValue(QString("suffix"), suffix, obj, QString("QString"));
    
        

    
    toJsonValue(QString("title"), title, obj, QString("QString"));
    
        

    
    toJsonValue(QString("type"), type, obj, QString("QString"));
    
        

    
    toJsonValue(QString("zip_code"), zip_code, obj, QString("QString"));
    
        

    
    QList<QString*>* hios_idsList = hios_ids;
    QJsonArray hios_idsJsonArray;
    toJsonArray((QList<void*>*)hios_ids, &hios_idsJsonArray, "hios_ids", "QString");

    obj->insert("hios_ids", hios_idsJsonArray);
    

    return obj;
}

bool
SWGProviderDetails::getAcceptingChangeOfPayorPatients() {
    return accepting_change_of_payor_patients;
}
void
SWGProviderDetails::setAcceptingChangeOfPayorPatients(bool accepting_change_of_payor_patients) {
    this->accepting_change_of_payor_patients = accepting_change_of_payor_patients;
}

bool
SWGProviderDetails::getAcceptingMedicaidPatients() {
    return accepting_medicaid_patients;
}
void
SWGProviderDetails::setAcceptingMedicaidPatients(bool accepting_medicaid_patients) {
    this->accepting_medicaid_patients = accepting_medicaid_patients;
}

bool
SWGProviderDetails::getAcceptingMedicarePatients() {
    return accepting_medicare_patients;
}
void
SWGProviderDetails::setAcceptingMedicarePatients(bool accepting_medicare_patients) {
    this->accepting_medicare_patients = accepting_medicare_patients;
}

bool
SWGProviderDetails::getAcceptingPrivatePatients() {
    return accepting_private_patients;
}
void
SWGProviderDetails::setAcceptingPrivatePatients(bool accepting_private_patients) {
    this->accepting_private_patients = accepting_private_patients;
}

bool
SWGProviderDetails::getAcceptingReferralPatients() {
    return accepting_referral_patients;
}
void
SWGProviderDetails::setAcceptingReferralPatients(bool accepting_referral_patients) {
    this->accepting_referral_patients = accepting_referral_patients;
}

QString*
SWGProviderDetails::getCity() {
    return city;
}
void
SWGProviderDetails::setCity(QString* city) {
    this->city = city;
}

QString*
SWGProviderDetails::getEmail() {
    return email;
}
void
SWGProviderDetails::setEmail(QString* email) {
    this->email = email;
}

QString*
SWGProviderDetails::getGender() {
    return gender;
}
void
SWGProviderDetails::setGender(QString* gender) {
    this->gender = gender;
}

QString*
SWGProviderDetails::getFirstName() {
    return first_name;
}
void
SWGProviderDetails::setFirstName(QString* first_name) {
    this->first_name = first_name;
}

qint32
SWGProviderDetails::getId() {
    return id;
}
void
SWGProviderDetails::setId(qint32 id) {
    this->id = id;
}

QString*
SWGProviderDetails::getLastName() {
    return last_name;
}
void
SWGProviderDetails::setLastName(QString* last_name) {
    this->last_name = last_name;
}

SWGNumber*
SWGProviderDetails::getLatitude() {
    return latitude;
}
void
SWGProviderDetails::setLatitude(SWGNumber* latitude) {
    this->latitude = latitude;
}

SWGNumber*
SWGProviderDetails::getLongitude() {
    return longitude;
}
void
SWGProviderDetails::setLongitude(SWGNumber* longitude) {
    this->longitude = longitude;
}

QString*
SWGProviderDetails::getMiddleName() {
    return middle_name;
}
void
SWGProviderDetails::setMiddleName(QString* middle_name) {
    this->middle_name = middle_name;
}

QList<qint32>*
SWGProviderDetails::getNetworkIds() {
    return network_ids;
}
void
SWGProviderDetails::setNetworkIds(QList<qint32>* network_ids) {
    this->network_ids = network_ids;
}

QString*
SWGProviderDetails::getOrganizationName() {
    return organization_name;
}
void
SWGProviderDetails::setOrganizationName(QString* organization_name) {
    this->organization_name = organization_name;
}

QString*
SWGProviderDetails::getPersonalPhone() {
    return personal_phone;
}
void
SWGProviderDetails::setPersonalPhone(QString* personal_phone) {
    this->personal_phone = personal_phone;
}

QString*
SWGProviderDetails::getPhone() {
    return phone;
}
void
SWGProviderDetails::setPhone(QString* phone) {
    this->phone = phone;
}

QString*
SWGProviderDetails::getPresentationName() {
    return presentation_name;
}
void
SWGProviderDetails::setPresentationName(QString* presentation_name) {
    this->presentation_name = presentation_name;
}

QString*
SWGProviderDetails::getSpecialty() {
    return specialty;
}
void
SWGProviderDetails::setSpecialty(QString* specialty) {
    this->specialty = specialty;
}

QString*
SWGProviderDetails::getState() {
    return state;
}
void
SWGProviderDetails::setState(QString* state) {
    this->state = state;
}

qint32
SWGProviderDetails::getStateId() {
    return state_id;
}
void
SWGProviderDetails::setStateId(qint32 state_id) {
    this->state_id = state_id;
}

QString*
SWGProviderDetails::getStreetLine1() {
    return street_line_1;
}
void
SWGProviderDetails::setStreetLine1(QString* street_line_1) {
    this->street_line_1 = street_line_1;
}

QString*
SWGProviderDetails::getStreetLine2() {
    return street_line_2;
}
void
SWGProviderDetails::setStreetLine2(QString* street_line_2) {
    this->street_line_2 = street_line_2;
}

QString*
SWGProviderDetails::getSuffix() {
    return suffix;
}
void
SWGProviderDetails::setSuffix(QString* suffix) {
    this->suffix = suffix;
}

QString*
SWGProviderDetails::getTitle() {
    return title;
}
void
SWGProviderDetails::setTitle(QString* title) {
    this->title = title;
}

QString*
SWGProviderDetails::getType() {
    return type;
}
void
SWGProviderDetails::setType(QString* type) {
    this->type = type;
}

QString*
SWGProviderDetails::getZipCode() {
    return zip_code;
}
void
SWGProviderDetails::setZipCode(QString* zip_code) {
    this->zip_code = zip_code;
}

QList<QString*>*
SWGProviderDetails::getHiosIds() {
    return hios_ids;
}
void
SWGProviderDetails::setHiosIds(QList<QString*>* hios_ids) {
    this->hios_ids = hios_ids;
}



} /* namespace Swagger */
