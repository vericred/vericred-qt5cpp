/*
 * SWGRatingArea.h
 * 
 * 
 */

#ifndef SWGRatingArea_H_
#define SWGRatingArea_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGRatingArea: public SWGObject {
public:
    SWGRatingArea();
    SWGRatingArea(QString* json);
    virtual ~SWGRatingArea();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGRatingArea* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
QString* getStateId();
    void setStateId(QString* state_id);

private:
    QString* id;
QString* state_id;
};

} /* namespace Swagger */

#endif /* SWGRatingArea_H_ */
