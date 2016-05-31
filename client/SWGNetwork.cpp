
#include "SWGNetwork.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGNetwork::SWGNetwork(QString* json) {
    init();
    this->fromJson(*json);
}

SWGNetwork::SWGNetwork() {
    init();
}

SWGNetwork::~SWGNetwork() {
    this->cleanup();
}

void
SWGNetwork::init() {
    id = NULL;
name = new QString("");
}

void
SWGNetwork::cleanup() {
    
if(name != NULL) {
        delete name;
    }
}

SWGNetwork*
SWGNetwork::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGNetwork::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&name, pJson["name"], "QString", "QString");
}

QString
SWGNetwork::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGNetwork::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        

    return obj;
}

qint32
SWGNetwork::getId() {
    return id;
}
void
SWGNetwork::setId(qint32 id) {
    this->id = id;
}

QString*
SWGNetwork::getName() {
    return name;
}
void
SWGNetwork::setName(QString* name) {
    this->name = name;
}



} /* namespace Swagger */

