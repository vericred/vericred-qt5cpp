
#include "SWGZipCountyBulk.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGZipCountyBulk::SWGZipCountyBulk(QString* json) {
    init();
    this->fromJson(*json);
}

SWGZipCountyBulk::SWGZipCountyBulk() {
    init();
}

SWGZipCountyBulk::~SWGZipCountyBulk() {
    this->cleanup();
}

void
SWGZipCountyBulk::init() {
    id = NULL;
rating_area_id = new QString("");
county_id = new QString("");
zip_code_id = new QString("");
}

void
SWGZipCountyBulk::cleanup() {
    
if(rating_area_id != NULL) {
        delete rating_area_id;
    }
if(county_id != NULL) {
        delete county_id;
    }
if(zip_code_id != NULL) {
        delete zip_code_id;
    }
}

SWGZipCountyBulk*
SWGZipCountyBulk::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGZipCountyBulk::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&rating_area_id, pJson["rating_area_id"], "QString", "QString");
setValue(&county_id, pJson["county_id"], "QString", "QString");
setValue(&zip_code_id, pJson["zip_code_id"], "QString", "QString");
}

QString
SWGZipCountyBulk::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGZipCountyBulk::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("rating_area_id"), rating_area_id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("county_id"), county_id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("zip_code_id"), zip_code_id, obj, QString("QString"));
    
        

    return obj;
}

qint32
SWGZipCountyBulk::getId() {
    return id;
}
void
SWGZipCountyBulk::setId(qint32 id) {
    this->id = id;
}

QString*
SWGZipCountyBulk::getRatingAreaId() {
    return rating_area_id;
}
void
SWGZipCountyBulk::setRatingAreaId(QString* rating_area_id) {
    this->rating_area_id = rating_area_id;
}

QString*
SWGZipCountyBulk::getCountyId() {
    return county_id;
}
void
SWGZipCountyBulk::setCountyId(QString* county_id) {
    this->county_id = county_id;
}

QString*
SWGZipCountyBulk::getZipCodeId() {
    return zip_code_id;
}
void
SWGZipCountyBulk::setZipCodeId(QString* zip_code_id) {
    this->zip_code_id = zip_code_id;
}



} /* namespace Swagger */

