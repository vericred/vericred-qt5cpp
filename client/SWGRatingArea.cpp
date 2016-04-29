
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
    id = NULL;
state_id = NULL;
}

void
SWGRatingArea::cleanup() {
    

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
    setValue(&id, pJson["id"], "qint32", "");
setValue(&state_id, pJson["state_id"], "qint32", "");
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
    obj->insert("id", QJsonValue(id));
obj->insert("state_id", QJsonValue(state_id));

    return obj;
}

qint32
SWGRatingArea::getId() {
    return id;
}
void
SWGRatingArea::setId(qint32 id) {
    this->id = id;
}

qint32
SWGRatingArea::getStateId() {
    return state_id;
}
void
SWGRatingArea::setStateId(qint32 state_id) {
    this->state_id = state_id;
}



} /* namespace Swagger */

