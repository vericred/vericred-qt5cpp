
#include "SWGCarrier.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGCarrier::SWGCarrier(QString* json) {
    init();
    this->fromJson(*json);
}

SWGCarrier::SWGCarrier() {
    init();
}

SWGCarrier::~SWGCarrier() {
    this->cleanup();
}

void
SWGCarrier::init() {
    id = NULL;
name = new QString("");
logo_path = new QString("");
}

void
SWGCarrier::cleanup() {
    
if(name != NULL) {
        delete name;
    }
if(logo_path != NULL) {
        delete logo_path;
    }
}

SWGCarrier*
SWGCarrier::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGCarrier::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&name, pJson["name"], "QString", "QString");
setValue(&logo_path, pJson["logo_path"], "QString", "QString");
}

QString
SWGCarrier::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGCarrier::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("logo_path"), logo_path, obj, QString("QString"));
    
        

    return obj;
}

qint32
SWGCarrier::getId() {
    return id;
}
void
SWGCarrier::setId(qint32 id) {
    this->id = id;
}

QString*
SWGCarrier::getName() {
    return name;
}
void
SWGCarrier::setName(QString* name) {
    this->name = name;
}

QString*
SWGCarrier::getLogoPath() {
    return logo_path;
}
void
SWGCarrier::setLogoPath(QString* logo_path) {
    this->logo_path = logo_path;
}



} /* namespace Swagger */

