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

/*
 * SWGProviderDetails.h
 * 
 * 
 */

#ifndef SWGProviderDetails_H_
#define SWGProviderDetails_H_

#include <QJsonObject>


#include "SWGNumber.h"
#include <QList>
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGProviderDetails: public SWGObject {
public:
    SWGProviderDetails();
    SWGProviderDetails(QString* json);
    virtual ~SWGProviderDetails();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGProviderDetails* fromJson(QString &jsonString);

    bool getAcceptingChangeOfPayorPatients();
    void setAcceptingChangeOfPayorPatients(bool accepting_change_of_payor_patients);
bool getAcceptingMedicaidPatients();
    void setAcceptingMedicaidPatients(bool accepting_medicaid_patients);
bool getAcceptingMedicarePatients();
    void setAcceptingMedicarePatients(bool accepting_medicare_patients);
bool getAcceptingPrivatePatients();
    void setAcceptingPrivatePatients(bool accepting_private_patients);
bool getAcceptingReferralPatients();
    void setAcceptingReferralPatients(bool accepting_referral_patients);
QString* getCity();
    void setCity(QString* city);
QString* getEmail();
    void setEmail(QString* email);
QString* getGender();
    void setGender(QString* gender);
QString* getFirstName();
    void setFirstName(QString* first_name);
qint32 getId();
    void setId(qint32 id);
QString* getLastName();
    void setLastName(QString* last_name);
SWGNumber* getLatitude();
    void setLatitude(SWGNumber* latitude);
SWGNumber* getLongitude();
    void setLongitude(SWGNumber* longitude);
QString* getMiddleName();
    void setMiddleName(QString* middle_name);
QList<qint32>* getNetworkIds();
    void setNetworkIds(QList<qint32>* network_ids);
QString* getOrganizationName();
    void setOrganizationName(QString* organization_name);
QString* getPersonalPhone();
    void setPersonalPhone(QString* personal_phone);
QString* getPhone();
    void setPhone(QString* phone);
QString* getPresentationName();
    void setPresentationName(QString* presentation_name);
QString* getSpecialty();
    void setSpecialty(QString* specialty);
QString* getState();
    void setState(QString* state);
qint32 getStateId();
    void setStateId(qint32 state_id);
QString* getStreetLine1();
    void setStreetLine1(QString* street_line_1);
QString* getStreetLine2();
    void setStreetLine2(QString* street_line_2);
QString* getSuffix();
    void setSuffix(QString* suffix);
QString* getTitle();
    void setTitle(QString* title);
QString* getType();
    void setType(QString* type);
QString* getZipCode();
    void setZipCode(QString* zip_code);
QList<QString*>* getHiosIds();
    void setHiosIds(QList<QString*>* hios_ids);

private:
    bool accepting_change_of_payor_patients;
bool accepting_medicaid_patients;
bool accepting_medicare_patients;
bool accepting_private_patients;
bool accepting_referral_patients;
QString* city;
QString* email;
QString* gender;
QString* first_name;
qint32 id;
QString* last_name;
SWGNumber* latitude;
SWGNumber* longitude;
QString* middle_name;
QList<qint32>* network_ids;
QString* organization_name;
QString* personal_phone;
QString* phone;
QString* presentation_name;
QString* specialty;
QString* state;
qint32 state_id;
QString* street_line_1;
QString* street_line_2;
QString* suffix;
QString* title;
QString* type;
QString* zip_code;
QList<QString*>* hios_ids;
};

} /* namespace Swagger */

#endif /* SWGProviderDetails_H_ */
