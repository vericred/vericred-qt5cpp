
#include "SWGDrugPackage.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGDrugPackage::SWGDrugPackage(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDrugPackage::SWGDrugPackage() {
    init();
}

SWGDrugPackage::~SWGDrugPackage() {
    this->cleanup();
}

void
SWGDrugPackage::init() {
    id = new QString("");
description = new QString("");
}

void
SWGDrugPackage::cleanup() {
    if(id != NULL) {
        delete id;
    }
if(description != NULL) {
        delete description;
    }
}

SWGDrugPackage*
SWGDrugPackage::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDrugPackage::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
setValue(&description, pJson["description"], "QString", "QString");
}

QString
SWGDrugPackage::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGDrugPackage::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("description"), description, obj, QString("QString"));
    
        

    return obj;
}

QString*
SWGDrugPackage::getId() {
    return id;
}
void
SWGDrugPackage::setId(QString* id) {
    this->id = id;
}

QString*
SWGDrugPackage::getDescription() {
    return description;
}
void
SWGDrugPackage::setDescription(QString* description) {
    this->description = description;
}



} /* namespace Swagger */

