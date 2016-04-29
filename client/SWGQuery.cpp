
#include "SWGQuery.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGQuery::SWGQuery(QString* json) {
    init();
    this->fromJson(*json);
}

SWGQuery::SWGQuery() {
    init();
}

SWGQuery::~SWGQuery() {
    this->cleanup();
}

void
SWGQuery::init() {
    applicants = new QList<SWGApplicant*>();
enrollment_date = NULL;
fips_code = new QString("");
household_income = new QString("");
household_size = new QString("");
market = new QString("");
providers = new QList<QString*>();
zip_code = new QString("");
}

void
SWGQuery::cleanup() {
    if(applicants != NULL) {
        QList<SWGApplicant*>* arr = applicants;
        foreach(SWGApplicant* o, *arr) {
            delete o;
        }
        delete applicants;
    }
if(enrollment_date != NULL) {
        delete enrollment_date;
    }
if(fips_code != NULL) {
        delete fips_code;
    }
if(household_income != NULL) {
        delete household_income;
    }
if(household_size != NULL) {
        delete household_size;
    }
if(market != NULL) {
        delete market;
    }
if(providers != NULL) {
        QList<QString*>* arr = providers;
        foreach(QString* o, *arr) {
            delete o;
        }
        delete providers;
    }
if(zip_code != NULL) {
        delete zip_code;
    }
}

SWGQuery*
SWGQuery::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGQuery::fromJsonObject(QJsonObject &pJson) {
    setValue(&applicants, pJson["applicants"], "QList", "SWGApplicant");
setValue(&enrollment_date, pJson["enrollment_date"], "QDate", "QDate");
setValue(&fips_code, pJson["fips_code"], "QString", "QString");
setValue(&household_income, pJson["household_income"], "QString", "QString");
setValue(&household_size, pJson["household_size"], "QString", "QString");
setValue(&market, pJson["market"], "QString", "QString");
setValue(&providers, pJson["providers"], "QList", "QString");
setValue(&zip_code, pJson["zip_code"], "QString", "QString");
}

QString
SWGQuery::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGQuery::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    QList<SWGApplicant*>* applicantsList = applicants;
    QJsonArray applicantsJsonArray;
    toJsonArray((QList<void*>*)applicants, &applicantsJsonArray, "applicants", "SWGApplicant");

    obj->insert("applicants", applicantsJsonArray);
    

    
    toJsonValue(QString("enrollment_date"), enrollment_date, obj, QString("QDate"));
    
        

    
    toJsonValue(QString("fips_code"), fips_code, obj, QString("QString"));
    
        

    
    toJsonValue(QString("household_income"), household_income, obj, QString("QString"));
    
        

    
    toJsonValue(QString("household_size"), household_size, obj, QString("QString"));
    
        

    
    toJsonValue(QString("market"), market, obj, QString("QString"));
    
        

    
    QList<QString*>* providersList = providers;
    QJsonArray providersJsonArray;
    toJsonArray((QList<void*>*)providers, &providersJsonArray, "providers", "QString");

    obj->insert("providers", providersJsonArray);
    

    
    toJsonValue(QString("zip_code"), zip_code, obj, QString("QString"));
    
        

    return obj;
}

QList<SWGApplicant*>*
SWGQuery::getApplicants() {
    return applicants;
}
void
SWGQuery::setApplicants(QList<SWGApplicant*>* applicants) {
    this->applicants = applicants;
}

QDate*
SWGQuery::getEnrollmentDate() {
    return enrollment_date;
}
void
SWGQuery::setEnrollmentDate(QDate* enrollment_date) {
    this->enrollment_date = enrollment_date;
}

QString*
SWGQuery::getFipsCode() {
    return fips_code;
}
void
SWGQuery::setFipsCode(QString* fips_code) {
    this->fips_code = fips_code;
}

QString*
SWGQuery::getHouseholdIncome() {
    return household_income;
}
void
SWGQuery::setHouseholdIncome(QString* household_income) {
    this->household_income = household_income;
}

QString*
SWGQuery::getHouseholdSize() {
    return household_size;
}
void
SWGQuery::setHouseholdSize(QString* household_size) {
    this->household_size = household_size;
}

QString*
SWGQuery::getMarket() {
    return market;
}
void
SWGQuery::setMarket(QString* market) {
    this->market = market;
}

QList<QString*>*
SWGQuery::getProviders() {
    return providers;
}
void
SWGQuery::setProviders(QList<QString*>* providers) {
    this->providers = providers;
}

QString*
SWGQuery::getZipCode() {
    return zip_code;
}
void
SWGQuery::setZipCode(QString* zip_code) {
    this->zip_code = zip_code;
}



} /* namespace Swagger */

