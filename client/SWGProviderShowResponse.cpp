
#include "SWGProviderShowResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGProviderShowResponse::SWGProviderShowResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGProviderShowResponse::SWGProviderShowResponse() {
    init();
}

SWGProviderShowResponse::~SWGProviderShowResponse() {
    this->cleanup();
}

void
SWGProviderShowResponse::init() {
    provider = new SWGProvider();
}

void
SWGProviderShowResponse::cleanup() {
    if(provider != NULL) {
        delete provider;
    }
}

SWGProviderShowResponse*
SWGProviderShowResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGProviderShowResponse::fromJsonObject(QJsonObject &pJson) {
    setValue(&provider, pJson["provider"], "SWGProvider", "SWGProvider");
}

QString
SWGProviderShowResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGProviderShowResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("provider"), provider, obj, QString("SWGProvider"));
    
        

    return obj;
}

SWGProvider*
SWGProviderShowResponse::getProvider() {
    return provider;
}
void
SWGProviderShowResponse::setProvider(SWGProvider* provider) {
    this->provider = provider;
}



} /* namespace Swagger */

