
#include "SWGPricing.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGPricing::SWGPricing(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPricing::SWGPricing() {
    init();
}

SWGPricing::~SWGPricing() {
    this->cleanup();
}

void
SWGPricing::init() {
    age = NULL;
effective_date = NULL;
expiration_date = NULL;
plan_id = NULL;
premium_child_only = 0.0;
premium_family = 0.0;
premium_single = 0.0;
premium_single_and_children = 0.0;
premium_single_and_spouse = 0.0;
premium_single_smoker = 0.0;
rating_area_id = new QString("");
}

void
SWGPricing::cleanup() {
    
if(effective_date != NULL) {
        delete effective_date;
    }
if(expiration_date != NULL) {
        delete expiration_date;
    }

if(premium_child_only != NULL) {
        delete premium_child_only;
    }
if(premium_family != NULL) {
        delete premium_family;
    }
if(premium_single != NULL) {
        delete premium_single;
    }
if(premium_single_and_children != NULL) {
        delete premium_single_and_children;
    }
if(premium_single_and_spouse != NULL) {
        delete premium_single_and_spouse;
    }
if(premium_single_smoker != NULL) {
        delete premium_single_smoker;
    }
if(rating_area_id != NULL) {
        delete rating_area_id;
    }
}

SWGPricing*
SWGPricing::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPricing::fromJsonObject(QJsonObject &pJson) {
    setValue(&age, pJson["age"], "qint32", "");
setValue(&effective_date, pJson["effective_date"], "QDate", "QDate");
setValue(&expiration_date, pJson["expiration_date"], "QDate", "QDate");
setValue(&plan_id, pJson["plan_id"], "qint32", "");
setValue(&premium_child_only, pJson["premium_child_only"], "SWGNumber", "SWGNumber");
setValue(&premium_family, pJson["premium_family"], "SWGNumber", "SWGNumber");
setValue(&premium_single, pJson["premium_single"], "SWGNumber", "SWGNumber");
setValue(&premium_single_and_children, pJson["premium_single_and_children"], "SWGNumber", "SWGNumber");
setValue(&premium_single_and_spouse, pJson["premium_single_and_spouse"], "SWGNumber", "SWGNumber");
setValue(&premium_single_smoker, pJson["premium_single_smoker"], "SWGNumber", "SWGNumber");
setValue(&rating_area_id, pJson["rating_area_id"], "QString", "QString");
}

QString
SWGPricing::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGPricing::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("age", QJsonValue(age));

    
    toJsonValue(QString("effective_date"), effective_date, obj, QString("QDate"));
    
        

    
    toJsonValue(QString("expiration_date"), expiration_date, obj, QString("QDate"));
    
        
obj->insert("plan_id", QJsonValue(plan_id));

    
    toJsonValue(QString("premium_child_only"), premium_child_only, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("premium_family"), premium_family, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("premium_single"), premium_single, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("premium_single_and_children"), premium_single_and_children, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("premium_single_and_spouse"), premium_single_and_spouse, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("premium_single_smoker"), premium_single_smoker, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("rating_area_id"), rating_area_id, obj, QString("QString"));
    
        

    return obj;
}

qint32
SWGPricing::getAge() {
    return age;
}
void
SWGPricing::setAge(qint32 age) {
    this->age = age;
}

QDate*
SWGPricing::getEffectiveDate() {
    return effective_date;
}
void
SWGPricing::setEffectiveDate(QDate* effective_date) {
    this->effective_date = effective_date;
}

QDate*
SWGPricing::getExpirationDate() {
    return expiration_date;
}
void
SWGPricing::setExpirationDate(QDate* expiration_date) {
    this->expiration_date = expiration_date;
}

qint32
SWGPricing::getPlanId() {
    return plan_id;
}
void
SWGPricing::setPlanId(qint32 plan_id) {
    this->plan_id = plan_id;
}

SWGNumber*
SWGPricing::getPremiumChildOnly() {
    return premium_child_only;
}
void
SWGPricing::setPremiumChildOnly(SWGNumber* premium_child_only) {
    this->premium_child_only = premium_child_only;
}

SWGNumber*
SWGPricing::getPremiumFamily() {
    return premium_family;
}
void
SWGPricing::setPremiumFamily(SWGNumber* premium_family) {
    this->premium_family = premium_family;
}

SWGNumber*
SWGPricing::getPremiumSingle() {
    return premium_single;
}
void
SWGPricing::setPremiumSingle(SWGNumber* premium_single) {
    this->premium_single = premium_single;
}

SWGNumber*
SWGPricing::getPremiumSingleAndChildren() {
    return premium_single_and_children;
}
void
SWGPricing::setPremiumSingleAndChildren(SWGNumber* premium_single_and_children) {
    this->premium_single_and_children = premium_single_and_children;
}

SWGNumber*
SWGPricing::getPremiumSingleAndSpouse() {
    return premium_single_and_spouse;
}
void
SWGPricing::setPremiumSingleAndSpouse(SWGNumber* premium_single_and_spouse) {
    this->premium_single_and_spouse = premium_single_and_spouse;
}

SWGNumber*
SWGPricing::getPremiumSingleSmoker() {
    return premium_single_smoker;
}
void
SWGPricing::setPremiumSingleSmoker(SWGNumber* premium_single_smoker) {
    this->premium_single_smoker = premium_single_smoker;
}

QString*
SWGPricing::getRatingAreaId() {
    return rating_area_id;
}
void
SWGPricing::setRatingAreaId(QString* rating_area_id) {
    this->rating_area_id = rating_area_id;
}



} /* namespace Swagger */

