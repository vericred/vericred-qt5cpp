
#include "SWGCarrierSubsidiary.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGCarrierSubsidiary::SWGCarrierSubsidiary(QString* json) {
    init();
    this->fromJson(*json);
}

SWGCarrierSubsidiary::SWGCarrierSubsidiary() {
    init();
}

SWGCarrierSubsidiary::~SWGCarrierSubsidiary() {
    this->cleanup();
}

void
SWGCarrierSubsidiary::init() {
    id = NULL;
name = new QString("");
alternate_name = new QString("");
}

void
SWGCarrierSubsidiary::cleanup() {
    
if(name != NULL) {
        delete name;
    }
if(alternate_name != NULL) {
        delete alternate_name;
    }
}

SWGCarrierSubsidiary*
SWGCarrierSubsidiary::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGCarrierSubsidiary::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&name, pJson["name"], "QString", "QString");
setValue(&alternate_name, pJson["alternate_name"], "QString", "QString");
}

QString
SWGCarrierSubsidiary::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGCarrierSubsidiary::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("alternate_name"), alternate_name, obj, QString("QString"));
    
        

    return obj;
}

qint32
SWGCarrierSubsidiary::getId() {
    return id;
}
void
SWGCarrierSubsidiary::setId(qint32 id) {
    this->id = id;
}

QString*
SWGCarrierSubsidiary::getName() {
    return name;
}
void
SWGCarrierSubsidiary::setName(QString* name) {
    this->name = name;
}

QString*
SWGCarrierSubsidiary::getAlternateName() {
    return alternate_name;
}
void
SWGCarrierSubsidiary::setAlternateName(QString* alternate_name) {
    this->alternate_name = alternate_name;
}



} /* namespace Swagger */

