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
