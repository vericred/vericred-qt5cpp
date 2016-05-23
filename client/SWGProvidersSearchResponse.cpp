
#include "SWGProvidersSearchResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGProvidersSearchResponse::SWGProvidersSearchResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGProvidersSearchResponse::SWGProvidersSearchResponse() {
    init();
}

SWGProvidersSearchResponse::~SWGProvidersSearchResponse() {
    this->cleanup();
}

void
SWGProvidersSearchResponse::init() {
    meta = new SWGMeta();
providers = new QList<SWGProvider*>();
states = new QList<SWGState*>();
}

void
SWGProvidersSearchResponse::cleanup() {
    if(meta != NULL) {
        delete meta;
    }
if(providers != NULL) {
        QList<SWGProvider*>* arr = providers;
        foreach(SWGProvider* o, *arr) {
            delete o;
        }
        delete providers;
    }
if(states != NULL) {
        QList<SWGState*>* arr = states;
        foreach(SWGState* o, *arr) {
            delete o;
        }
        delete states;
    }
}

SWGProvidersSearchResponse*
SWGProvidersSearchResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGProvidersSearchResponse::fromJsonObject(QJsonObject &pJson) {
    setValue(&meta, pJson["meta"], "SWGMeta", "SWGMeta");
setValue(&providers, pJson["providers"], "QList", "SWGProvider");
setValue(&states, pJson["states"], "QList", "SWGState");
}

QString
SWGProvidersSearchResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGProvidersSearchResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("meta"), meta, obj, QString("SWGMeta"));
    
        

    
    QList<SWGProvider*>* providersList = providers;
    QJsonArray providersJsonArray;
    toJsonArray((QList<void*>*)providers, &providersJsonArray, "providers", "SWGProvider");

    obj->insert("providers", providersJsonArray);
    

    
    QList<SWGState*>* statesList = states;
    QJsonArray statesJsonArray;
    toJsonArray((QList<void*>*)states, &statesJsonArray, "states", "SWGState");

    obj->insert("states", statesJsonArray);
    

    return obj;
}

SWGMeta*
SWGProvidersSearchResponse::getMeta() {
    return meta;
}
void
SWGProvidersSearchResponse::setMeta(SWGMeta* meta) {
    this->meta = meta;
}

QList<SWGProvider*>*
SWGProvidersSearchResponse::getProviders() {
    return providers;
}
void
SWGProvidersSearchResponse::setProviders(QList<SWGProvider*>* providers) {
    this->providers = providers;
}

QList<SWGState*>*
SWGProvidersSearchResponse::getStates() {
    return states;
}
void
SWGProvidersSearchResponse::setStates(QList<SWGState*>* states) {
    this->states = states;
}



} /* namespace Swagger */

