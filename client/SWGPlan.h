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
 * SWGPlan.h
 * 
 * 
 */

#ifndef SWGPlan_H_
#define SWGPlan_H_

#include <QJsonObject>


#include "SWGNumber.h"
#include <QList>
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGPlan: public SWGObject {
public:
    SWGPlan();
    SWGPlan(QString* json);
    virtual ~SWGPlan();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGPlan* fromJson(QString &jsonString);

    bool getAdultDental();
    void setAdultDental(bool adult_dental);
bool getAge29Rider();
    void setAge29Rider(bool age29_rider);
QString* getAmbulance();
    void setAmbulance(QString* ambulance);
QString* getBenefitsSummaryUrl();
    void setBenefitsSummaryUrl(QString* benefits_summary_url);
QString* getBuyLink();
    void setBuyLink(QString* buy_link);
QString* getCarrierName();
    void setCarrierName(QString* carrier_name);
bool getChildDental();
    void setChildDental(bool child_dental);
QString* getChildEyewear();
    void setChildEyewear(QString* child_eyewear);
QString* getChildEyeExam();
    void setChildEyeExam(QString* child_eye_exam);
QString* getCustomerServicePhoneNumber();
    void setCustomerServicePhoneNumber(QString* customer_service_phone_number);
QString* getDurableMedicalEquipment();
    void setDurableMedicalEquipment(QString* durable_medical_equipment);
QString* getDiagnosticTest();
    void setDiagnosticTest(QString* diagnostic_test);
bool getDpRider();
    void setDpRider(bool dp_rider);
QString* getDrugFormularyUrl();
    void setDrugFormularyUrl(QString* drug_formulary_url);
QString* getEffectiveDate();
    void setEffectiveDate(QString* effective_date);
QString* getExpirationDate();
    void setExpirationDate(QString* expiration_date);
QString* getEmergencyRoom();
    void setEmergencyRoom(QString* emergency_room);
QString* getFamilyDrugDeductible();
    void setFamilyDrugDeductible(QString* family_drug_deductible);
QString* getFamilyDrugMoop();
    void setFamilyDrugMoop(QString* family_drug_moop);
QString* getFamilyMedicalDeductible();
    void setFamilyMedicalDeductible(QString* family_medical_deductible);
QString* getFamilyMedicalMoop();
    void setFamilyMedicalMoop(QString* family_medical_moop);
bool getFpRider();
    void setFpRider(bool fp_rider);
QString* getGenericDrugs();
    void setGenericDrugs(QString* generic_drugs);
QString* getHabilitationServices();
    void setHabilitationServices(QString* habilitation_services);
QString* getHiosIssuerId();
    void setHiosIssuerId(QString* hios_issuer_id);
QString* getHomeHealthCare();
    void setHomeHealthCare(QString* home_health_care);
QString* getHospiceService();
    void setHospiceService(QString* hospice_service);
QString* getId();
    void setId(QString* id);
QString* getImaging();
    void setImaging(QString* imaging);
QList<qint32>* getInNetworkIds();
    void setInNetworkIds(QList<qint32>* in_network_ids);
QString* getIndividualDrugDeductible();
    void setIndividualDrugDeductible(QString* individual_drug_deductible);
QString* getIndividualDrugMoop();
    void setIndividualDrugMoop(QString* individual_drug_moop);
QString* getIndividualMedicalDeductible();
    void setIndividualMedicalDeductible(QString* individual_medical_deductible);
QString* getIndividualMedicalMoop();
    void setIndividualMedicalMoop(QString* individual_medical_moop);
QString* getInpatientBirth();
    void setInpatientBirth(QString* inpatient_birth);
QString* getInpatientFacility();
    void setInpatientFacility(QString* inpatient_facility);
QString* getInpatientMentalHealth();
    void setInpatientMentalHealth(QString* inpatient_mental_health);
QString* getInpatientPhysician();
    void setInpatientPhysician(QString* inpatient_physician);
QString* getInpatientSubstance();
    void setInpatientSubstance(QString* inpatient_substance);
QString* getLevel();
    void setLevel(QString* level);
QString* getLogoUrl();
    void setLogoUrl(QString* logo_url);
QString* getName();
    void setName(QString* name);
qint32 getNetworkSize();
    void setNetworkSize(qint32 network_size);
QString* getNonPreferredBrandDrugs();
    void setNonPreferredBrandDrugs(QString* non_preferred_brand_drugs);
bool getOnMarket();
    void setOnMarket(bool on_market);
bool getOffMarket();
    void setOffMarket(bool off_market);
bool getOutOfNetworkCoverage();
    void setOutOfNetworkCoverage(bool out_of_network_coverage);
QList<qint32>* getOutOfNetworkIds();
    void setOutOfNetworkIds(QList<qint32>* out_of_network_ids);
QString* getOutpatientFacility();
    void setOutpatientFacility(QString* outpatient_facility);
QString* getOutpatientMentalHealth();
    void setOutpatientMentalHealth(QString* outpatient_mental_health);
QString* getOutpatientPhysician();
    void setOutpatientPhysician(QString* outpatient_physician);
QString* getOutpatientSubstance();
    void setOutpatientSubstance(QString* outpatient_substance);
QString* getPlanMarket();
    void setPlanMarket(QString* plan_market);
QString* getPlanType();
    void setPlanType(QString* plan_type);
QString* getPreferredBrandDrugs();
    void setPreferredBrandDrugs(QString* preferred_brand_drugs);
QString* getPrenatalPostnatalCare();
    void setPrenatalPostnatalCare(QString* prenatal_postnatal_care);
QString* getPreventativeCare();
    void setPreventativeCare(QString* preventative_care);
SWGNumber* getPremiumSubsidized();
    void setPremiumSubsidized(SWGNumber* premium_subsidized);
SWGNumber* getPremium();
    void setPremium(SWGNumber* premium);
QString* getPrimaryCarePhysician();
    void setPrimaryCarePhysician(QString* primary_care_physician);
QString* getRehabilitationServices();
    void setRehabilitationServices(QString* rehabilitation_services);
QString* getSkilledNursing();
    void setSkilledNursing(QString* skilled_nursing);
QString* getSpecialist();
    void setSpecialist(QString* specialist);
QString* getSpecialtyDrugs();
    void setSpecialtyDrugs(QString* specialty_drugs);
QString* getUrgentCare();
    void setUrgentCare(QString* urgent_care);

private:
    bool adult_dental;
bool age29_rider;
QString* ambulance;
QString* benefits_summary_url;
QString* buy_link;
QString* carrier_name;
bool child_dental;
QString* child_eyewear;
QString* child_eye_exam;
QString* customer_service_phone_number;
QString* durable_medical_equipment;
QString* diagnostic_test;
bool dp_rider;
QString* drug_formulary_url;
QString* effective_date;
QString* expiration_date;
QString* emergency_room;
QString* family_drug_deductible;
QString* family_drug_moop;
QString* family_medical_deductible;
QString* family_medical_moop;
bool fp_rider;
QString* generic_drugs;
QString* habilitation_services;
QString* hios_issuer_id;
QString* home_health_care;
QString* hospice_service;
QString* id;
QString* imaging;
QList<qint32>* in_network_ids;
QString* individual_drug_deductible;
QString* individual_drug_moop;
QString* individual_medical_deductible;
QString* individual_medical_moop;
QString* inpatient_birth;
QString* inpatient_facility;
QString* inpatient_mental_health;
QString* inpatient_physician;
QString* inpatient_substance;
QString* level;
QString* logo_url;
QString* name;
qint32 network_size;
QString* non_preferred_brand_drugs;
bool on_market;
bool off_market;
bool out_of_network_coverage;
QList<qint32>* out_of_network_ids;
QString* outpatient_facility;
QString* outpatient_mental_health;
QString* outpatient_physician;
QString* outpatient_substance;
QString* plan_market;
QString* plan_type;
QString* preferred_brand_drugs;
QString* prenatal_postnatal_care;
QString* preventative_care;
SWGNumber* premium_subsidized;
SWGNumber* premium;
QString* primary_care_physician;
QString* rehabilitation_services;
QString* skilled_nursing;
QString* specialist;
QString* specialty_drugs;
QString* urgent_care;
};

} /* namespace Swagger */

#endif /* SWGPlan_H_ */
