
#include "SWGCounty.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGCounty::SWGCounty(QString* json) {
    init();
    this->fromJson(*json);
}

SWGCounty::SWGCounty() {
    init();
}

SWGCounty::~SWGCounty() {
    this->cleanup();
}

void
SWGCounty::init() {
    id = NULL;
fips_code = new QString("");
name = new QString("");
state_code = new QString("");
state_id = NULL;
state_live = false;
state_live_for_business = false;
}

void
SWGCounty::cleanup() {
    
if(fips_code != NULL) {
        delete fips_code;
    }
if(name != NULL) {
        delete name;
    }
if(state_code != NULL) {
        delete state_code;
    }



}

SWGCounty*
SWGCounty::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGCounty::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&fips_code, pJson["fips_code"], "QString", "QString");
setValue(&name, pJson["name"], "QString", "QString");
setValue(&state_code, pJson["state_code"], "QString", "QString");
setValue(&state_id, pJson["state_id"], "qint32", "");
setValue(&state_live, pJson["state_live"], "bool", "");
setValue(&state_live_for_business, pJson["state_live_for_business"], "bool", "");
}

QString
SWGCounty::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGCounty::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("fips_code"), fips_code, obj, QString("QString"));
    
        

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("state_code"), state_code, obj, QString("QString"));
    
        
obj->insert("state_id", QJsonValue(state_id));
obj->insert("state_live", QJsonValue(state_live));
obj->insert("state_live_for_business", QJsonValue(state_live_for_business));

    return obj;
}

qint32
SWGCounty::getId() {
    return id;
}
void
SWGCounty::setId(qint32 id) {
    this->id = id;
}

QString*
SWGCounty::getFipsCode() {
    return fips_code;
}
void
SWGCounty::setFipsCode(QString* fips_code) {
    this->fips_code = fips_code;
}

QString*
SWGCounty::getName() {
    return name;
}
void
SWGCounty::setName(QString* name) {
    this->name = name;
}

QString*
SWGCounty::getStateCode() {
    return state_code;
}
void
SWGCounty::setStateCode(QString* state_code) {
    this->state_code = state_code;
}

qint32
SWGCounty::getStateId() {
    return state_id;
}
void
SWGCounty::setStateId(qint32 state_id) {
    this->state_id = state_id;
}

bool
SWGCounty::getStateLive() {
    return state_live;
}
void
SWGCounty::setStateLive(bool state_live) {
    this->state_live = state_live;
}

bool
SWGCounty::getStateLiveForBusiness() {
    return state_live_for_business;
}
void
SWGCounty::setStateLiveForBusiness(bool state_live_for_business) {
    this->state_live_for_business = state_live_for_business;
}



} /* namespace Swagger */

