
#include "SWGRatingArea.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGRatingArea::SWGRatingArea(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRatingArea::SWGRatingArea() {
    init();
}

SWGRatingArea::~SWGRatingArea() {
    this->cleanup();
}

void
SWGRatingArea::init() {
    id = new QString("");
state_id = new QString("");
}

void
SWGRatingArea::cleanup() {
    if(id != NULL) {
        delete id;
    }
if(state_id != NULL) {
        delete state_id;
    }
}

SWGRatingArea*
SWGRatingArea::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRatingArea::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
setValue(&state_id, pJson["state_id"], "QString", "QString");
}

QString
SWGRatingArea::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGRatingArea::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("state_id"), state_id, obj, QString("QString"));
    
        

    return obj;
}

QString*
SWGRatingArea::getId() {
    return id;
}
void
SWGRatingArea::setId(QString* id) {
    this->id = id;
}

QString*
SWGRatingArea::getStateId() {
    return state_id;
}
void
SWGRatingArea::setStateId(QString* state_id) {
    this->state_id = state_id;
}



} /* namespace Swagger */

