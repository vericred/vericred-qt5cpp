
#include "SWGPlanZipCounty.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGPlanZipCounty::SWGPlanZipCounty(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPlanZipCounty::SWGPlanZipCounty() {
    init();
}

SWGPlanZipCounty::~SWGPlanZipCounty() {
    this->cleanup();
}

void
SWGPlanZipCounty::init() {
    plan_id = NULL;
county_id = NULL;
zip_code_id = NULL;
}

void
SWGPlanZipCounty::cleanup() {
    


}

SWGPlanZipCounty*
SWGPlanZipCounty::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPlanZipCounty::fromJsonObject(QJsonObject &pJson) {
    setValue(&plan_id, pJson["plan_id"], "qint32", "");
setValue(&county_id, pJson["county_id"], "qint32", "");
setValue(&zip_code_id, pJson["zip_code_id"], "qint32", "");
}

QString
SWGPlanZipCounty::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGPlanZipCounty::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("plan_id", QJsonValue(plan_id));
obj->insert("county_id", QJsonValue(county_id));
obj->insert("zip_code_id", QJsonValue(zip_code_id));

    return obj;
}

qint32
SWGPlanZipCounty::getPlanId() {
    return plan_id;
}
void
SWGPlanZipCounty::setPlanId(qint32 plan_id) {
    this->plan_id = plan_id;
}

qint32
SWGPlanZipCounty::getCountyId() {
    return county_id;
}
void
SWGPlanZipCounty::setCountyId(qint32 county_id) {
    this->county_id = county_id;
}

qint32
SWGPlanZipCounty::getZipCodeId() {
    return zip_code_id;
}
void
SWGPlanZipCounty::setZipCodeId(qint32 zip_code_id) {
    this->zip_code_id = zip_code_id;
}



} /* namespace Swagger */

