
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
rating_area_id = NULL;
}

void
SWGPricing::cleanup() {
    
if(effective_date != NULL) {
        delete effective_date;
    }
if(expiration_date != NULL) {
        delete expiration_date;
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
setValue(&rating_area_id, pJson["rating_area_id"], "qint32", "");
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
obj->insert("rating_area_id", QJsonValue(rating_area_id));

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

qint32
SWGPricing::getRatingAreaId() {
    return rating_area_id;
}
void
SWGPricing::setRatingAreaId(qint32 rating_area_id) {
    this->rating_area_id = rating_area_id;
}



} /* namespace Swagger */

