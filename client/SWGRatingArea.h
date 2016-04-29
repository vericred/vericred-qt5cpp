/*
 * SWGRatingArea.h
 * 
 * 
 */

#ifndef SWGRatingArea_H_
#define SWGRatingArea_H_

#include <QJsonObject>



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

    qint32 getId();
    void setId(qint32 id);
qint32 getStateId();
    void setStateId(qint32 state_id);

private:
    qint32 id;
qint32 state_id;
};

} /* namespace Swagger */

#endif /* SWGRatingArea_H_ */
