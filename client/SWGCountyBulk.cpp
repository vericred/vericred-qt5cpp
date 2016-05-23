
#include "SWGCountyBulk.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGCountyBulk::SWGCountyBulk(QString* json) {
    init();
    this->fromJson(*json);
}

SWGCountyBulk::SWGCountyBulk() {
    init();
}

SWGCountyBulk::~SWGCountyBulk() {
    this->cleanup();
}

void
SWGCountyBulk::init() {
    id = new QString("");
name = new QString("");
state_id = new QString("");
}

void
SWGCountyBulk::cleanup() {
    if(id != NULL) {
        delete id;
    }
if(name != NULL) {
        delete name;
    }
if(state_id != NULL) {
        delete state_id;
    }
}

SWGCountyBulk*
SWGCountyBulk::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGCountyBulk::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
setValue(&name, pJson["name"], "QString", "QString");
setValue(&state_id, pJson["state_id"], "QString", "QString");
}

QString
SWGCountyBulk::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGCountyBulk::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("state_id"), state_id, obj, QString("QString"));
    
        

    return obj;
}

QString*
SWGCountyBulk::getId() {
    return id;
}
void
SWGCountyBulk::setId(QString* id) {
    this->id = id;
}

QString*
SWGCountyBulk::getName() {
    return name;
}
void
SWGCountyBulk::setName(QString* name) {
    this->name = name;
}

QString*
SWGCountyBulk::getStateId() {
    return state_id;
}
void
SWGCountyBulk::setStateId(QString* state_id) {
    this->state_id = state_id;
}



} /* namespace Swagger */

