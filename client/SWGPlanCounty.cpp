
#include "SWGPlanCounty.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGPlanCounty::SWGPlanCounty(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPlanCounty::SWGPlanCounty() {
    init();
}

SWGPlanCounty::~SWGPlanCounty() {
    this->cleanup();
}

void
SWGPlanCounty::init() {
    plan_id = NULL;
county_id = NULL;
}

void
SWGPlanCounty::cleanup() {
    

}

SWGPlanCounty*
SWGPlanCounty::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPlanCounty::fromJsonObject(QJsonObject &pJson) {
    setValue(&plan_id, pJson["plan_id"], "qint32", "");
setValue(&county_id, pJson["county_id"], "qint32", "");
}

QString
SWGPlanCounty::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGPlanCounty::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("plan_id", QJsonValue(plan_id));
obj->insert("county_id", QJsonValue(county_id));

    return obj;
}

qint32
SWGPlanCounty::getPlanId() {
    return plan_id;
}
void
SWGPlanCounty::setPlanId(qint32 plan_id) {
    this->plan_id = plan_id;
}

qint32
SWGPlanCounty::getCountyId() {
    return county_id;
}
void
SWGPlanCounty::setCountyId(qint32 county_id) {
    this->county_id = county_id;
}



} /* namespace Swagger */

