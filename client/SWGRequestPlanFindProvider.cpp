
#include "SWGRequestPlanFindProvider.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGRequestPlanFindProvider::SWGRequestPlanFindProvider(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRequestPlanFindProvider::SWGRequestPlanFindProvider() {
    init();
}

SWGRequestPlanFindProvider::~SWGRequestPlanFindProvider() {
    this->cleanup();
}

void
SWGRequestPlanFindProvider::init() {
    npi = NULL;
}

void
SWGRequestPlanFindProvider::cleanup() {
    
}

SWGRequestPlanFindProvider*
SWGRequestPlanFindProvider::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRequestPlanFindProvider::fromJsonObject(QJsonObject &pJson) {
    setValue(&npi, pJson["npi"], "qint32", "");
}

QString
SWGRequestPlanFindProvider::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGRequestPlanFindProvider::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("npi", QJsonValue(npi));

    return obj;
}

qint32
SWGRequestPlanFindProvider::getNpi() {
    return npi;
}
void
SWGRequestPlanFindProvider::setNpi(qint32 npi) {
    this->npi = npi;
}



} /* namespace Swagger */

