
#include "SWGState.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGState::SWGState(QString* json) {
    init();
    this->fromJson(*json);
}

SWGState::SWGState() {
    init();
}

SWGState::~SWGState() {
    this->cleanup();
}

void
SWGState::init() {
    id = NULL;
name = new QString("");
code = new QString("");
fips_number = new QString("");
last_date_for_individual = NULL;
last_date_for_shop = NULL;
live_for_business = false;
live_for_consumers = false;
}

void
SWGState::cleanup() {
    
if(name != NULL) {
        delete name;
    }
if(code != NULL) {
        delete code;
    }
if(fips_number != NULL) {
        delete fips_number;
    }
if(last_date_for_individual != NULL) {
        delete last_date_for_individual;
    }
if(last_date_for_shop != NULL) {
        delete last_date_for_shop;
    }


}

SWGState*
SWGState::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGState::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&name, pJson["name"], "QString", "QString");
setValue(&code, pJson["code"], "QString", "QString");
setValue(&fips_number, pJson["fips_number"], "QString", "QString");
setValue(&last_date_for_individual, pJson["last_date_for_individual"], "QDate", "QDate");
setValue(&last_date_for_shop, pJson["last_date_for_shop"], "QDate", "QDate");
setValue(&live_for_business, pJson["live_for_business"], "bool", "");
setValue(&live_for_consumers, pJson["live_for_consumers"], "bool", "");
}

QString
SWGState::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGState::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("code"), code, obj, QString("QString"));
    
        

    
    toJsonValue(QString("fips_number"), fips_number, obj, QString("QString"));
    
        

    
    toJsonValue(QString("last_date_for_individual"), last_date_for_individual, obj, QString("QDate"));
    
        

    
    toJsonValue(QString("last_date_for_shop"), last_date_for_shop, obj, QString("QDate"));
    
        
obj->insert("live_for_business", QJsonValue(live_for_business));
obj->insert("live_for_consumers", QJsonValue(live_for_consumers));

    return obj;
}

qint32
SWGState::getId() {
    return id;
}
void
SWGState::setId(qint32 id) {
    this->id = id;
}

QString*
SWGState::getName() {
    return name;
}
void
SWGState::setName(QString* name) {
    this->name = name;
}

QString*
SWGState::getCode() {
    return code;
}
void
SWGState::setCode(QString* code) {
    this->code = code;
}

QString*
SWGState::getFipsNumber() {
    return fips_number;
}
void
SWGState::setFipsNumber(QString* fips_number) {
    this->fips_number = fips_number;
}

QDate*
SWGState::getLastDateForIndividual() {
    return last_date_for_individual;
}
void
SWGState::setLastDateForIndividual(QDate* last_date_for_individual) {
    this->last_date_for_individual = last_date_for_individual;
}

QDate*
SWGState::getLastDateForShop() {
    return last_date_for_shop;
}
void
SWGState::setLastDateForShop(QDate* last_date_for_shop) {
    this->last_date_for_shop = last_date_for_shop;
}

bool
SWGState::getLiveForBusiness() {
    return live_for_business;
}
void
SWGState::setLiveForBusiness(bool live_for_business) {
    this->live_for_business = live_for_business;
}

bool
SWGState::getLiveForConsumers() {
    return live_for_consumers;
}
void
SWGState::setLiveForConsumers(bool live_for_consumers) {
    this->live_for_consumers = live_for_consumers;
}



} /* namespace Swagger */

