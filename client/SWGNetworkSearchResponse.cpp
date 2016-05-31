
#include "SWGNetworkSearchResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGNetworkSearchResponse::SWGNetworkSearchResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGNetworkSearchResponse::SWGNetworkSearchResponse() {
    init();
}

SWGNetworkSearchResponse::~SWGNetworkSearchResponse() {
    this->cleanup();
}

void
SWGNetworkSearchResponse::init() {
    meta = new SWGMeta();
networks = new QList<SWGNetwork*>();
}

void
SWGNetworkSearchResponse::cleanup() {
    if(meta != NULL) {
        delete meta;
    }
if(networks != NULL) {
        QList<SWGNetwork*>* arr = networks;
        foreach(SWGNetwork* o, *arr) {
            delete o;
        }
        delete networks;
    }
}

SWGNetworkSearchResponse*
SWGNetworkSearchResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGNetworkSearchResponse::fromJsonObject(QJsonObject &pJson) {
    setValue(&meta, pJson["meta"], "SWGMeta", "SWGMeta");
setValue(&networks, pJson["networks"], "QList", "SWGNetwork");
}

QString
SWGNetworkSearchResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGNetworkSearchResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("meta"), meta, obj, QString("SWGMeta"));
    
        

    
    QList<SWGNetwork*>* networksList = networks;
    QJsonArray networksJsonArray;
    toJsonArray((QList<void*>*)networks, &networksJsonArray, "networks", "SWGNetwork");

    obj->insert("networks", networksJsonArray);
    

    return obj;
}

SWGMeta*
SWGNetworkSearchResponse::getMeta() {
    return meta;
}
void
SWGNetworkSearchResponse::setMeta(SWGMeta* meta) {
    this->meta = meta;
}

QList<SWGNetwork*>*
SWGNetworkSearchResponse::getNetworks() {
    return networks;
}
void
SWGNetworkSearchResponse::setNetworks(QList<SWGNetwork*>* networks) {
    this->networks = networks;
}



} /* namespace Swagger */

