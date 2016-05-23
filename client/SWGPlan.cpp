
#include "SWGPlan.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGPlan::SWGPlan(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPlan::SWGPlan() {
    init();
}

SWGPlan::~SWGPlan() {
    this->cleanup();
}

void
SWGPlan::init() {
    adult_dental = false;
ambulance = new QString("");
benefits_summary_url = new QString("");
buy_link = new QString("");
carrier_name = new QString("");
child_dental = false;
child_eyewear = new QString("");
child_eye_exam = new QString("");
customer_service_phone_number = new QString("");
durable_medical_equipment = new QString("");
diagnostic_test = new QString("");
drug_formulary_url = new QString("");
effective_date = new QString("");
expiration_date = new QString("");
emergency_room = new QString("");
family_drug_deductible = new QString("");
family_drug_moop = new QString("");
family_medical_deductible = new QString("");
family_medical_moop = new QString("");
generic_drugs = new QString("");
habilitation_services = new QString("");
hios_issuer_id = new QString("");
home_health_care = new QString("");
hospice_service = new QString("");
id = new QString("");
imaging = new QString("");
in_network_ids = new QList<qint32>();
individual_drug_deductible = new QString("");
individual_drug_moop = new QString("");
individual_medical_deductible = new QString("");
individual_medical_moop = new QString("");
inpatient_birth = new QString("");
inpatient_facility = new QString("");
inpatient_mental_health = new QString("");
inpatient_physician = new QString("");
inpatient_substance = new QString("");
level = new QString("");
logo_url = new QString("");
name = new QString("");
network_size = NULL;
non_preferred_brand_drugs = new QString("");
on_market = false;
off_market = false;
out_of_network_coverage = false;
out_of_network_ids = new QList<qint32>();
outpatient_facility = new QString("");
outpatient_mental_health = new QString("");
outpatient_physician = new QString("");
outpatient_substance = new QString("");
plan_market = new QString("");
plan_type = new QString("");
preferred_brand_drugs = new QString("");
prenatal_postnatal_care = new QString("");
preventative_care = new QString("");
premium_subsidized = 0.0;
premium = 0.0;
primary_care_physician = new QString("");
rehabilitation_services = new QString("");
skilled_nursing = new QString("");
specialist = new QString("");
specialty_drugs = new QString("");
urgent_care = new QString("");
}

void
SWGPlan::cleanup() {
    
if(ambulance != NULL) {
        delete ambulance;
    }
if(benefits_summary_url != NULL) {
        delete benefits_summary_url;
    }
if(buy_link != NULL) {
        delete buy_link;
    }
if(carrier_name != NULL) {
        delete carrier_name;
    }

if(child_eyewear != NULL) {
        delete child_eyewear;
    }
if(child_eye_exam != NULL) {
        delete child_eye_exam;
    }
if(customer_service_phone_number != NULL) {
        delete customer_service_phone_number;
    }
if(durable_medical_equipment != NULL) {
        delete durable_medical_equipment;
    }
if(diagnostic_test != NULL) {
        delete diagnostic_test;
    }
if(drug_formulary_url != NULL) {
        delete drug_formulary_url;
    }
if(effective_date != NULL) {
        delete effective_date;
    }
if(expiration_date != NULL) {
        delete expiration_date;
    }
if(emergency_room != NULL) {
        delete emergency_room;
    }
if(family_drug_deductible != NULL) {
        delete family_drug_deductible;
    }
if(family_drug_moop != NULL) {
        delete family_drug_moop;
    }
if(family_medical_deductible != NULL) {
        delete family_medical_deductible;
    }
if(family_medical_moop != NULL) {
        delete family_medical_moop;
    }
if(generic_drugs != NULL) {
        delete generic_drugs;
    }
if(habilitation_services != NULL) {
        delete habilitation_services;
    }
if(hios_issuer_id != NULL) {
        delete hios_issuer_id;
    }
if(home_health_care != NULL) {
        delete home_health_care;
    }
if(hospice_service != NULL) {
        delete hospice_service;
    }
if(id != NULL) {
        delete id;
    }
if(imaging != NULL) {
        delete imaging;
    }

if(individual_drug_deductible != NULL) {
        delete individual_drug_deductible;
    }
if(individual_drug_moop != NULL) {
        delete individual_drug_moop;
    }
if(individual_medical_deductible != NULL) {
        delete individual_medical_deductible;
    }
if(individual_medical_moop != NULL) {
        delete individual_medical_moop;
    }
if(inpatient_birth != NULL) {
        delete inpatient_birth;
    }
if(inpatient_facility != NULL) {
        delete inpatient_facility;
    }
if(inpatient_mental_health != NULL) {
        delete inpatient_mental_health;
    }
if(inpatient_physician != NULL) {
        delete inpatient_physician;
    }
if(inpatient_substance != NULL) {
        delete inpatient_substance;
    }
if(level != NULL) {
        delete level;
    }
if(logo_url != NULL) {
        delete logo_url;
    }
if(name != NULL) {
        delete name;
    }

if(non_preferred_brand_drugs != NULL) {
        delete non_preferred_brand_drugs;
    }




if(outpatient_facility != NULL) {
        delete outpatient_facility;
    }
if(outpatient_mental_health != NULL) {
        delete outpatient_mental_health;
    }
if(outpatient_physician != NULL) {
        delete outpatient_physician;
    }
if(outpatient_substance != NULL) {
        delete outpatient_substance;
    }
if(plan_market != NULL) {
        delete plan_market;
    }
if(plan_type != NULL) {
        delete plan_type;
    }
if(preferred_brand_drugs != NULL) {
        delete preferred_brand_drugs;
    }
if(prenatal_postnatal_care != NULL) {
        delete prenatal_postnatal_care;
    }
if(preventative_care != NULL) {
        delete preventative_care;
    }
if(premium_subsidized != NULL) {
        delete premium_subsidized;
    }
if(premium != NULL) {
        delete premium;
    }
if(primary_care_physician != NULL) {
        delete primary_care_physician;
    }
if(rehabilitation_services != NULL) {
        delete rehabilitation_services;
    }
if(skilled_nursing != NULL) {
        delete skilled_nursing;
    }
if(specialist != NULL) {
        delete specialist;
    }
if(specialty_drugs != NULL) {
        delete specialty_drugs;
    }
if(urgent_care != NULL) {
        delete urgent_care;
    }
}

SWGPlan*
SWGPlan::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPlan::fromJsonObject(QJsonObject &pJson) {
    setValue(&adult_dental, pJson["adult_dental"], "bool", "");
setValue(&ambulance, pJson["ambulance"], "QString", "QString");
setValue(&benefits_summary_url, pJson["benefits_summary_url"], "QString", "QString");
setValue(&buy_link, pJson["buy_link"], "QString", "QString");
setValue(&carrier_name, pJson["carrier_name"], "QString", "QString");
setValue(&child_dental, pJson["child_dental"], "bool", "");
setValue(&child_eyewear, pJson["child_eyewear"], "QString", "QString");
setValue(&child_eye_exam, pJson["child_eye_exam"], "QString", "QString");
setValue(&customer_service_phone_number, pJson["customer_service_phone_number"], "QString", "QString");
setValue(&durable_medical_equipment, pJson["durable_medical_equipment"], "QString", "QString");
setValue(&diagnostic_test, pJson["diagnostic_test"], "QString", "QString");
setValue(&drug_formulary_url, pJson["drug_formulary_url"], "QString", "QString");
setValue(&effective_date, pJson["effective_date"], "QString", "QString");
setValue(&expiration_date, pJson["expiration_date"], "QString", "QString");
setValue(&emergency_room, pJson["emergency_room"], "QString", "QString");
setValue(&family_drug_deductible, pJson["family_drug_deductible"], "QString", "QString");
setValue(&family_drug_moop, pJson["family_drug_moop"], "QString", "QString");
setValue(&family_medical_deductible, pJson["family_medical_deductible"], "QString", "QString");
setValue(&family_medical_moop, pJson["family_medical_moop"], "QString", "QString");
setValue(&generic_drugs, pJson["generic_drugs"], "QString", "QString");
setValue(&habilitation_services, pJson["habilitation_services"], "QString", "QString");
setValue(&hios_issuer_id, pJson["hios_issuer_id"], "QString", "QString");
setValue(&home_health_care, pJson["home_health_care"], "QString", "QString");
setValue(&hospice_service, pJson["hospice_service"], "QString", "QString");
setValue(&id, pJson["id"], "QString", "QString");
setValue(&imaging, pJson["imaging"], "QString", "QString");
setValue(&in_network_ids, pJson["in_network_ids"], "QList", "");
setValue(&individual_drug_deductible, pJson["individual_drug_deductible"], "QString", "QString");
setValue(&individual_drug_moop, pJson["individual_drug_moop"], "QString", "QString");
setValue(&individual_medical_deductible, pJson["individual_medical_deductible"], "QString", "QString");
setValue(&individual_medical_moop, pJson["individual_medical_moop"], "QString", "QString");
setValue(&inpatient_birth, pJson["inpatient_birth"], "QString", "QString");
setValue(&inpatient_facility, pJson["inpatient_facility"], "QString", "QString");
setValue(&inpatient_mental_health, pJson["inpatient_mental_health"], "QString", "QString");
setValue(&inpatient_physician, pJson["inpatient_physician"], "QString", "QString");
setValue(&inpatient_substance, pJson["inpatient_substance"], "QString", "QString");
setValue(&level, pJson["level"], "QString", "QString");
setValue(&logo_url, pJson["logo_url"], "QString", "QString");
setValue(&name, pJson["name"], "QString", "QString");
setValue(&network_size, pJson["network_size"], "qint32", "");
setValue(&non_preferred_brand_drugs, pJson["non_preferred_brand_drugs"], "QString", "QString");
setValue(&on_market, pJson["on_market"], "bool", "");
setValue(&off_market, pJson["off_market"], "bool", "");
setValue(&out_of_network_coverage, pJson["out_of_network_coverage"], "bool", "");
setValue(&out_of_network_ids, pJson["out_of_network_ids"], "QList", "");
setValue(&outpatient_facility, pJson["outpatient_facility"], "QString", "QString");
setValue(&outpatient_mental_health, pJson["outpatient_mental_health"], "QString", "QString");
setValue(&outpatient_physician, pJson["outpatient_physician"], "QString", "QString");
setValue(&outpatient_substance, pJson["outpatient_substance"], "QString", "QString");
setValue(&plan_market, pJson["plan_market"], "QString", "QString");
setValue(&plan_type, pJson["plan_type"], "QString", "QString");
setValue(&preferred_brand_drugs, pJson["preferred_brand_drugs"], "QString", "QString");
setValue(&prenatal_postnatal_care, pJson["prenatal_postnatal_care"], "QString", "QString");
setValue(&preventative_care, pJson["preventative_care"], "QString", "QString");
setValue(&premium_subsidized, pJson["premium_subsidized"], "SWGNumber", "SWGNumber");
setValue(&premium, pJson["premium"], "SWGNumber", "SWGNumber");
setValue(&primary_care_physician, pJson["primary_care_physician"], "QString", "QString");
setValue(&rehabilitation_services, pJson["rehabilitation_services"], "QString", "QString");
setValue(&skilled_nursing, pJson["skilled_nursing"], "QString", "QString");
setValue(&specialist, pJson["specialist"], "QString", "QString");
setValue(&specialty_drugs, pJson["specialty_drugs"], "QString", "QString");
setValue(&urgent_care, pJson["urgent_care"], "QString", "QString");
}

QString
SWGPlan::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGPlan::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("adult_dental", QJsonValue(adult_dental));

    
    toJsonValue(QString("ambulance"), ambulance, obj, QString("QString"));
    
        

    
    toJsonValue(QString("benefits_summary_url"), benefits_summary_url, obj, QString("QString"));
    
        

    
    toJsonValue(QString("buy_link"), buy_link, obj, QString("QString"));
    
        

    
    toJsonValue(QString("carrier_name"), carrier_name, obj, QString("QString"));
    
        
obj->insert("child_dental", QJsonValue(child_dental));

    
    toJsonValue(QString("child_eyewear"), child_eyewear, obj, QString("QString"));
    
        

    
    toJsonValue(QString("child_eye_exam"), child_eye_exam, obj, QString("QString"));
    
        

    
    toJsonValue(QString("customer_service_phone_number"), customer_service_phone_number, obj, QString("QString"));
    
        

    
    toJsonValue(QString("durable_medical_equipment"), durable_medical_equipment, obj, QString("QString"));
    
        

    
    toJsonValue(QString("diagnostic_test"), diagnostic_test, obj, QString("QString"));
    
        

    
    toJsonValue(QString("drug_formulary_url"), drug_formulary_url, obj, QString("QString"));
    
        

    
    toJsonValue(QString("effective_date"), effective_date, obj, QString("QString"));
    
        

    
    toJsonValue(QString("expiration_date"), expiration_date, obj, QString("QString"));
    
        

    
    toJsonValue(QString("emergency_room"), emergency_room, obj, QString("QString"));
    
        

    
    toJsonValue(QString("family_drug_deductible"), family_drug_deductible, obj, QString("QString"));
    
        

    
    toJsonValue(QString("family_drug_moop"), family_drug_moop, obj, QString("QString"));
    
        

    
    toJsonValue(QString("family_medical_deductible"), family_medical_deductible, obj, QString("QString"));
    
        

    
    toJsonValue(QString("family_medical_moop"), family_medical_moop, obj, QString("QString"));
    
        

    
    toJsonValue(QString("generic_drugs"), generic_drugs, obj, QString("QString"));
    
        

    
    toJsonValue(QString("habilitation_services"), habilitation_services, obj, QString("QString"));
    
        

    
    toJsonValue(QString("hios_issuer_id"), hios_issuer_id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("home_health_care"), home_health_care, obj, QString("QString"));
    
        

    
    toJsonValue(QString("hospice_service"), hospice_service, obj, QString("QString"));
    
        

    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("imaging"), imaging, obj, QString("QString"));
    
        
obj->insert("in_network_ids", QJsonValue(in_network_ids));

    
    toJsonValue(QString("individual_drug_deductible"), individual_drug_deductible, obj, QString("QString"));
    
        

    
    toJsonValue(QString("individual_drug_moop"), individual_drug_moop, obj, QString("QString"));
    
        

    
    toJsonValue(QString("individual_medical_deductible"), individual_medical_deductible, obj, QString("QString"));
    
        

    
    toJsonValue(QString("individual_medical_moop"), individual_medical_moop, obj, QString("QString"));
    
        

    
    toJsonValue(QString("inpatient_birth"), inpatient_birth, obj, QString("QString"));
    
        

    
    toJsonValue(QString("inpatient_facility"), inpatient_facility, obj, QString("QString"));
    
        

    
    toJsonValue(QString("inpatient_mental_health"), inpatient_mental_health, obj, QString("QString"));
    
        

    
    toJsonValue(QString("inpatient_physician"), inpatient_physician, obj, QString("QString"));
    
        

    
    toJsonValue(QString("inpatient_substance"), inpatient_substance, obj, QString("QString"));
    
        

    
    toJsonValue(QString("level"), level, obj, QString("QString"));
    
        

    
    toJsonValue(QString("logo_url"), logo_url, obj, QString("QString"));
    
        

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        
obj->insert("network_size", QJsonValue(network_size));

    
    toJsonValue(QString("non_preferred_brand_drugs"), non_preferred_brand_drugs, obj, QString("QString"));
    
        
obj->insert("on_market", QJsonValue(on_market));
obj->insert("off_market", QJsonValue(off_market));
obj->insert("out_of_network_coverage", QJsonValue(out_of_network_coverage));
obj->insert("out_of_network_ids", QJsonValue(out_of_network_ids));

    
    toJsonValue(QString("outpatient_facility"), outpatient_facility, obj, QString("QString"));
    
        

    
    toJsonValue(QString("outpatient_mental_health"), outpatient_mental_health, obj, QString("QString"));
    
        

    
    toJsonValue(QString("outpatient_physician"), outpatient_physician, obj, QString("QString"));
    
        

    
    toJsonValue(QString("outpatient_substance"), outpatient_substance, obj, QString("QString"));
    
        

    
    toJsonValue(QString("plan_market"), plan_market, obj, QString("QString"));
    
        

    
    toJsonValue(QString("plan_type"), plan_type, obj, QString("QString"));
    
        

    
    toJsonValue(QString("preferred_brand_drugs"), preferred_brand_drugs, obj, QString("QString"));
    
        

    
    toJsonValue(QString("prenatal_postnatal_care"), prenatal_postnatal_care, obj, QString("QString"));
    
        

    
    toJsonValue(QString("preventative_care"), preventative_care, obj, QString("QString"));
    
        

    
    toJsonValue(QString("premium_subsidized"), premium_subsidized, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("premium"), premium, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("primary_care_physician"), primary_care_physician, obj, QString("QString"));
    
        

    
    toJsonValue(QString("rehabilitation_services"), rehabilitation_services, obj, QString("QString"));
    
        

    
    toJsonValue(QString("skilled_nursing"), skilled_nursing, obj, QString("QString"));
    
        

    
    toJsonValue(QString("specialist"), specialist, obj, QString("QString"));
    
        

    
    toJsonValue(QString("specialty_drugs"), specialty_drugs, obj, QString("QString"));
    
        

    
    toJsonValue(QString("urgent_care"), urgent_care, obj, QString("QString"));
    
        

    return obj;
}

bool
SWGPlan::getAdultDental() {
    return adult_dental;
}
void
SWGPlan::setAdultDental(bool adult_dental) {
    this->adult_dental = adult_dental;
}

QString*
SWGPlan::getAmbulance() {
    return ambulance;
}
void
SWGPlan::setAmbulance(QString* ambulance) {
    this->ambulance = ambulance;
}

QString*
SWGPlan::getBenefitsSummaryUrl() {
    return benefits_summary_url;
}
void
SWGPlan::setBenefitsSummaryUrl(QString* benefits_summary_url) {
    this->benefits_summary_url = benefits_summary_url;
}

QString*
SWGPlan::getBuyLink() {
    return buy_link;
}
void
SWGPlan::setBuyLink(QString* buy_link) {
    this->buy_link = buy_link;
}

QString*
SWGPlan::getCarrierName() {
    return carrier_name;
}
void
SWGPlan::setCarrierName(QString* carrier_name) {
    this->carrier_name = carrier_name;
}

bool
SWGPlan::getChildDental() {
    return child_dental;
}
void
SWGPlan::setChildDental(bool child_dental) {
    this->child_dental = child_dental;
}

QString*
SWGPlan::getChildEyewear() {
    return child_eyewear;
}
void
SWGPlan::setChildEyewear(QString* child_eyewear) {
    this->child_eyewear = child_eyewear;
}

QString*
SWGPlan::getChildEyeExam() {
    return child_eye_exam;
}
void
SWGPlan::setChildEyeExam(QString* child_eye_exam) {
    this->child_eye_exam = child_eye_exam;
}

QString*
SWGPlan::getCustomerServicePhoneNumber() {
    return customer_service_phone_number;
}
void
SWGPlan::setCustomerServicePhoneNumber(QString* customer_service_phone_number) {
    this->customer_service_phone_number = customer_service_phone_number;
}

QString*
SWGPlan::getDurableMedicalEquipment() {
    return durable_medical_equipment;
}
void
SWGPlan::setDurableMedicalEquipment(QString* durable_medical_equipment) {
    this->durable_medical_equipment = durable_medical_equipment;
}

QString*
SWGPlan::getDiagnosticTest() {
    return diagnostic_test;
}
void
SWGPlan::setDiagnosticTest(QString* diagnostic_test) {
    this->diagnostic_test = diagnostic_test;
}

QString*
SWGPlan::getDrugFormularyUrl() {
    return drug_formulary_url;
}
void
SWGPlan::setDrugFormularyUrl(QString* drug_formulary_url) {
    this->drug_formulary_url = drug_formulary_url;
}

QString*
SWGPlan::getEffectiveDate() {
    return effective_date;
}
void
SWGPlan::setEffectiveDate(QString* effective_date) {
    this->effective_date = effective_date;
}

QString*
SWGPlan::getExpirationDate() {
    return expiration_date;
}
void
SWGPlan::setExpirationDate(QString* expiration_date) {
    this->expiration_date = expiration_date;
}

QString*
SWGPlan::getEmergencyRoom() {
    return emergency_room;
}
void
SWGPlan::setEmergencyRoom(QString* emergency_room) {
    this->emergency_room = emergency_room;
}

QString*
SWGPlan::getFamilyDrugDeductible() {
    return family_drug_deductible;
}
void
SWGPlan::setFamilyDrugDeductible(QString* family_drug_deductible) {
    this->family_drug_deductible = family_drug_deductible;
}

QString*
SWGPlan::getFamilyDrugMoop() {
    return family_drug_moop;
}
void
SWGPlan::setFamilyDrugMoop(QString* family_drug_moop) {
    this->family_drug_moop = family_drug_moop;
}

QString*
SWGPlan::getFamilyMedicalDeductible() {
    return family_medical_deductible;
}
void
SWGPlan::setFamilyMedicalDeductible(QString* family_medical_deductible) {
    this->family_medical_deductible = family_medical_deductible;
}

QString*
SWGPlan::getFamilyMedicalMoop() {
    return family_medical_moop;
}
void
SWGPlan::setFamilyMedicalMoop(QString* family_medical_moop) {
    this->family_medical_moop = family_medical_moop;
}

QString*
SWGPlan::getGenericDrugs() {
    return generic_drugs;
}
void
SWGPlan::setGenericDrugs(QString* generic_drugs) {
    this->generic_drugs = generic_drugs;
}

QString*
SWGPlan::getHabilitationServices() {
    return habilitation_services;
}
void
SWGPlan::setHabilitationServices(QString* habilitation_services) {
    this->habilitation_services = habilitation_services;
}

QString*
SWGPlan::getHiosIssuerId() {
    return hios_issuer_id;
}
void
SWGPlan::setHiosIssuerId(QString* hios_issuer_id) {
    this->hios_issuer_id = hios_issuer_id;
}

QString*
SWGPlan::getHomeHealthCare() {
    return home_health_care;
}
void
SWGPlan::setHomeHealthCare(QString* home_health_care) {
    this->home_health_care = home_health_care;
}

QString*
SWGPlan::getHospiceService() {
    return hospice_service;
}
void
SWGPlan::setHospiceService(QString* hospice_service) {
    this->hospice_service = hospice_service;
}

QString*
SWGPlan::getId() {
    return id;
}
void
SWGPlan::setId(QString* id) {
    this->id = id;
}

QString*
SWGPlan::getImaging() {
    return imaging;
}
void
SWGPlan::setImaging(QString* imaging) {
    this->imaging = imaging;
}

QList<qint32>*
SWGPlan::getInNetworkIds() {
    return in_network_ids;
}
void
SWGPlan::setInNetworkIds(QList<qint32>* in_network_ids) {
    this->in_network_ids = in_network_ids;
}

QString*
SWGPlan::getIndividualDrugDeductible() {
    return individual_drug_deductible;
}
void
SWGPlan::setIndividualDrugDeductible(QString* individual_drug_deductible) {
    this->individual_drug_deductible = individual_drug_deductible;
}

QString*
SWGPlan::getIndividualDrugMoop() {
    return individual_drug_moop;
}
void
SWGPlan::setIndividualDrugMoop(QString* individual_drug_moop) {
    this->individual_drug_moop = individual_drug_moop;
}

QString*
SWGPlan::getIndividualMedicalDeductible() {
    return individual_medical_deductible;
}
void
SWGPlan::setIndividualMedicalDeductible(QString* individual_medical_deductible) {
    this->individual_medical_deductible = individual_medical_deductible;
}

QString*
SWGPlan::getIndividualMedicalMoop() {
    return individual_medical_moop;
}
void
SWGPlan::setIndividualMedicalMoop(QString* individual_medical_moop) {
    this->individual_medical_moop = individual_medical_moop;
}

QString*
SWGPlan::getInpatientBirth() {
    return inpatient_birth;
}
void
SWGPlan::setInpatientBirth(QString* inpatient_birth) {
    this->inpatient_birth = inpatient_birth;
}

QString*
SWGPlan::getInpatientFacility() {
    return inpatient_facility;
}
void
SWGPlan::setInpatientFacility(QString* inpatient_facility) {
    this->inpatient_facility = inpatient_facility;
}

QString*
SWGPlan::getInpatientMentalHealth() {
    return inpatient_mental_health;
}
void
SWGPlan::setInpatientMentalHealth(QString* inpatient_mental_health) {
    this->inpatient_mental_health = inpatient_mental_health;
}

QString*
SWGPlan::getInpatientPhysician() {
    return inpatient_physician;
}
void
SWGPlan::setInpatientPhysician(QString* inpatient_physician) {
    this->inpatient_physician = inpatient_physician;
}

QString*
SWGPlan::getInpatientSubstance() {
    return inpatient_substance;
}
void
SWGPlan::setInpatientSubstance(QString* inpatient_substance) {
    this->inpatient_substance = inpatient_substance;
}

QString*
SWGPlan::getLevel() {
    return level;
}
void
SWGPlan::setLevel(QString* level) {
    this->level = level;
}

QString*
SWGPlan::getLogoUrl() {
    return logo_url;
}
void
SWGPlan::setLogoUrl(QString* logo_url) {
    this->logo_url = logo_url;
}

QString*
SWGPlan::getName() {
    return name;
}
void
SWGPlan::setName(QString* name) {
    this->name = name;
}

qint32
SWGPlan::getNetworkSize() {
    return network_size;
}
void
SWGPlan::setNetworkSize(qint32 network_size) {
    this->network_size = network_size;
}

QString*
SWGPlan::getNonPreferredBrandDrugs() {
    return non_preferred_brand_drugs;
}
void
SWGPlan::setNonPreferredBrandDrugs(QString* non_preferred_brand_drugs) {
    this->non_preferred_brand_drugs = non_preferred_brand_drugs;
}

bool
SWGPlan::getOnMarket() {
    return on_market;
}
void
SWGPlan::setOnMarket(bool on_market) {
    this->on_market = on_market;
}

bool
SWGPlan::getOffMarket() {
    return off_market;
}
void
SWGPlan::setOffMarket(bool off_market) {
    this->off_market = off_market;
}

bool
SWGPlan::getOutOfNetworkCoverage() {
    return out_of_network_coverage;
}
void
SWGPlan::setOutOfNetworkCoverage(bool out_of_network_coverage) {
    this->out_of_network_coverage = out_of_network_coverage;
}

QList<qint32>*
SWGPlan::getOutOfNetworkIds() {
    return out_of_network_ids;
}
void
SWGPlan::setOutOfNetworkIds(QList<qint32>* out_of_network_ids) {
    this->out_of_network_ids = out_of_network_ids;
}

QString*
SWGPlan::getOutpatientFacility() {
    return outpatient_facility;
}
void
SWGPlan::setOutpatientFacility(QString* outpatient_facility) {
    this->outpatient_facility = outpatient_facility;
}

QString*
SWGPlan::getOutpatientMentalHealth() {
    return outpatient_mental_health;
}
void
SWGPlan::setOutpatientMentalHealth(QString* outpatient_mental_health) {
    this->outpatient_mental_health = outpatient_mental_health;
}

QString*
SWGPlan::getOutpatientPhysician() {
    return outpatient_physician;
}
void
SWGPlan::setOutpatientPhysician(QString* outpatient_physician) {
    this->outpatient_physician = outpatient_physician;
}

QString*
SWGPlan::getOutpatientSubstance() {
    return outpatient_substance;
}
void
SWGPlan::setOutpatientSubstance(QString* outpatient_substance) {
    this->outpatient_substance = outpatient_substance;
}

QString*
SWGPlan::getPlanMarket() {
    return plan_market;
}
void
SWGPlan::setPlanMarket(QString* plan_market) {
    this->plan_market = plan_market;
}

QString*
SWGPlan::getPlanType() {
    return plan_type;
}
void
SWGPlan::setPlanType(QString* plan_type) {
    this->plan_type = plan_type;
}

QString*
SWGPlan::getPreferredBrandDrugs() {
    return preferred_brand_drugs;
}
void
SWGPlan::setPreferredBrandDrugs(QString* preferred_brand_drugs) {
    this->preferred_brand_drugs = preferred_brand_drugs;
}

QString*
SWGPlan::getPrenatalPostnatalCare() {
    return prenatal_postnatal_care;
}
void
SWGPlan::setPrenatalPostnatalCare(QString* prenatal_postnatal_care) {
    this->prenatal_postnatal_care = prenatal_postnatal_care;
}

QString*
SWGPlan::getPreventativeCare() {
    return preventative_care;
}
void
SWGPlan::setPreventativeCare(QString* preventative_care) {
    this->preventative_care = preventative_care;
}

SWGNumber*
SWGPlan::getPremiumSubsidized() {
    return premium_subsidized;
}
void
SWGPlan::setPremiumSubsidized(SWGNumber* premium_subsidized) {
    this->premium_subsidized = premium_subsidized;
}

SWGNumber*
SWGPlan::getPremium() {
    return premium;
}
void
SWGPlan::setPremium(SWGNumber* premium) {
    this->premium = premium;
}

QString*
SWGPlan::getPrimaryCarePhysician() {
    return primary_care_physician;
}
void
SWGPlan::setPrimaryCarePhysician(QString* primary_care_physician) {
    this->primary_care_physician = primary_care_physician;
}

QString*
SWGPlan::getRehabilitationServices() {
    return rehabilitation_services;
}
void
SWGPlan::setRehabilitationServices(QString* rehabilitation_services) {
    this->rehabilitation_services = rehabilitation_services;
}

QString*
SWGPlan::getSkilledNursing() {
    return skilled_nursing;
}
void
SWGPlan::setSkilledNursing(QString* skilled_nursing) {
    this->skilled_nursing = skilled_nursing;
}

QString*
SWGPlan::getSpecialist() {
    return specialist;
}
void
SWGPlan::setSpecialist(QString* specialist) {
    this->specialist = specialist;
}

QString*
SWGPlan::getSpecialtyDrugs() {
    return specialty_drugs;
}
void
SWGPlan::setSpecialtyDrugs(QString* specialty_drugs) {
    this->specialty_drugs = specialty_drugs;
}

QString*
SWGPlan::getUrgentCare() {
    return urgent_care;
}
void
SWGPlan::setUrgentCare(QString* urgent_care) {
    this->urgent_care = urgent_care;
}



} /* namespace Swagger */

