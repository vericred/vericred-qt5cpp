
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
drug_packages = new QList<SWGDrugPackage*>();
fips_code = new QString("");
household_income = NULL;
household_size = NULL;
market = new QString("");
providers = new QList<SWGRequestPlanFindProvider*>();
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
        QList<SWGDrugPackage*>* arr = drug_packages;
        foreach(SWGDrugPackage* o, *arr) {
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
setValue(&drug_packages, pJson["drug_packages"], "QList", "SWGDrugPackage");
setValue(&fips_code, pJson["fips_code"], "QString", "QString");
setValue(&household_income, pJson["household_income"], "qint32", "");
setValue(&household_size, pJson["household_size"], "qint32", "");
setValue(&market, pJson["market"], "QString", "QString");
setValue(&providers, pJson["providers"], "QList", "SWGRequestPlanFindProvider");
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
    
        

    
    QList<SWGDrugPackage*>* drug_packagesList = drug_packages;
    QJsonArray drug_packagesJsonArray;
    toJsonArray((QList<void*>*)drug_packages, &drug_packagesJsonArray, "drug_packages", "SWGDrugPackage");

    obj->insert("drug_packages", drug_packagesJsonArray);
    

    
    toJsonValue(QString("fips_code"), fips_code, obj, QString("QString"));
    
        
obj->insert("household_income", QJsonValue(household_income));
obj->insert("household_size", QJsonValue(household_size));

    
    toJsonValue(QString("market"), market, obj, QString("QString"));
    
        

    
    QList<SWGRequestPlanFindProvider*>* providersList = providers;
    QJsonArray providersJsonArray;
    toJsonArray((QList<void*>*)providers, &providersJsonArray, "providers", "SWGRequestPlanFindProvider");

    obj->insert("providers", providersJsonArray);
    

    
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

QList<SWGDrugPackage*>*
SWGRequestPlanFind::getDrugPackages() {
    return drug_packages;
}
void
SWGRequestPlanFind::setDrugPackages(QList<SWGDrugPackage*>* drug_packages) {
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

QString*
SWGRequestPlanFind::getZipCode() {
    return zip_code;
}
void
SWGRequestPlanFind::setZipCode(QString* zip_code) {
    this->zip_code = zip_code;
}



} /* namespace Swagger */

