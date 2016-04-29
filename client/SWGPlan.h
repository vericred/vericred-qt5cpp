/*
 * SWGPlan.h
 * 
 * 
 */

#ifndef SWGPlan_H_
#define SWGPlan_H_

#include <QJsonObject>


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
QString* getCustomerServicePhoneNumber();
    void setCustomerServicePhoneNumber(QString* customer_service_phone_number);
QString* getDurableMedicalEquipment();
    void setDurableMedicalEquipment(QString* durable_medical_equipment);
QString* getDiagnosticTest();
    void setDiagnosticTest(QString* diagnostic_test);
QString* getDrugFormularyUrl();
    void setDrugFormularyUrl(QString* drug_formulary_url);
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
QString* getGenericDrugs();
    void setGenericDrugs(QString* generic_drugs);
QString* getHiosIssuerId();
    void setHiosIssuerId(QString* hios_issuer_id);
QString* getId();
    void setId(QString* id);
QString* getImaging();
    void setImaging(QString* imaging);
QString* getIndividualDrugDeductible();
    void setIndividualDrugDeductible(QString* individual_drug_deductible);
QString* getIndividualDrugMoop();
    void setIndividualDrugMoop(QString* individual_drug_moop);
QString* getIndividualMedicalDeductible();
    void setIndividualMedicalDeductible(QString* individual_medical_deductible);
QString* getIndividualMedicalMoop();
    void setIndividualMedicalMoop(QString* individual_medical_moop);
QString* getInpatientFacility();
    void setInpatientFacility(QString* inpatient_facility);
QString* getInpatientPhysician();
    void setInpatientPhysician(QString* inpatient_physician);
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
QString* getOutpatientFacility();
    void setOutpatientFacility(QString* outpatient_facility);
QString* getOutpatientMentalHealth();
    void setOutpatientMentalHealth(QString* outpatient_mental_health);
QString* getOutpatientPhysician();
    void setOutpatientPhysician(QString* outpatient_physician);
QString* getPlanMarket();
    void setPlanMarket(QString* plan_market);
QString* getPlanType();
    void setPlanType(QString* plan_type);
QString* getPreferredBrandDrugs();
    void setPreferredBrandDrugs(QString* preferred_brand_drugs);
QString* getPreventativeCare();
    void setPreventativeCare(QString* preventative_care);
QString* getPrimaryCarePhysician();
    void setPrimaryCarePhysician(QString* primary_care_physician);
QString* getRehabilitationServices();
    void setRehabilitationServices(QString* rehabilitation_services);
QString* getSpecialist();
    void setSpecialist(QString* specialist);
QString* getSpecialtyDrugs();
    void setSpecialtyDrugs(QString* specialty_drugs);
QString* getUrgentCare();
    void setUrgentCare(QString* urgent_care);

private:
    bool adult_dental;
QString* ambulance;
QString* benefits_summary_url;
QString* buy_link;
QString* carrier_name;
bool child_dental;
QString* child_eyewear;
QString* customer_service_phone_number;
QString* durable_medical_equipment;
QString* diagnostic_test;
QString* drug_formulary_url;
QString* emergency_room;
QString* family_drug_deductible;
QString* family_drug_moop;
QString* family_medical_deductible;
QString* family_medical_moop;
QString* generic_drugs;
QString* hios_issuer_id;
QString* id;
QString* imaging;
QString* individual_drug_deductible;
QString* individual_drug_moop;
QString* individual_medical_deductible;
QString* individual_medical_moop;
QString* inpatient_facility;
QString* inpatient_physician;
QString* level;
QString* logo_url;
QString* name;
qint32 network_size;
QString* non_preferred_brand_drugs;
bool on_market;
bool off_market;
bool out_of_network_coverage;
QString* outpatient_facility;
QString* outpatient_mental_health;
QString* outpatient_physician;
QString* plan_market;
QString* plan_type;
QString* preferred_brand_drugs;
QString* preventative_care;
QString* primary_care_physician;
QString* rehabilitation_services;
QString* specialist;
QString* specialty_drugs;
QString* urgent_care;
};

} /* namespace Swagger */

#endif /* SWGPlan_H_ */
