
#include "SWGInline_response_200.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGInline_response_200::SWGInline_response_200(QString* json) {
    init();
    this->fromJson(*json);
}

SWGInline_response_200::SWGInline_response_200() {
    init();
}

SWGInline_response_200::~SWGInline_response_200() {
    this->cleanup();
}

void
SWGInline_response_200::init() {
    meta = NULL;
providers = new QList<SWGProvider*>();
}

void
SWGInline_response_200::cleanup() {
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
}

SWGInline_response_200*
SWGInline_response_200::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGInline_response_200::fromJsonObject(QJsonObject &pJson) {
    setValue(&meta, pJson["meta"], "SWGObject", "SWGObject");
setValue(&providers, pJson["providers"], "QList", "SWGProvider");
}

QString
SWGInline_response_200::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGInline_response_200::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("meta"), meta, obj, QString("SWGObject"));
    
        

    
    QList<SWGProvider*>* providersList = providers;
    QJsonArray providersJsonArray;
    toJsonArray((QList<void*>*)providers, &providersJsonArray, "providers", "SWGProvider");

    obj->insert("providers", providersJsonArray);
    

    return obj;
}

SWGObject*
SWGInline_response_200::getMeta() {
    return meta;
}
void
SWGInline_response_200::setMeta(SWGObject* meta) {
    this->meta = meta;
}

QList<SWGProvider*>*
SWGInline_response_200::getProviders() {
    return providers;
}
void
SWGInline_response_200::setProviders(QList<SWGProvider*>* providers) {
    this->providers = providers;
}



} /* namespace Swagger */

