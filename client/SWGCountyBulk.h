/*
 * SWGCountyBulk.h
 * 
 * 
 */

#ifndef SWGCountyBulk_H_
#define SWGCountyBulk_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGCountyBulk: public SWGObject {
public:
    SWGCountyBulk();
    SWGCountyBulk(QString* json);
    virtual ~SWGCountyBulk();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGCountyBulk* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
QString* getName();
    void setName(QString* name);
QString* getStateId();
    void setStateId(QString* state_id);

private:
    QString* id;
QString* name;
QString* state_id;
};

} /* namespace Swagger */

#endif /* SWGCountyBulk_H_ */
