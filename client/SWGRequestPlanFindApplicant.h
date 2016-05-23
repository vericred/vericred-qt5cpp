/*
 * SWGRequestPlanFindApplicant.h
 * 
 * 
 */

#ifndef SWGRequestPlanFindApplicant_H_
#define SWGRequestPlanFindApplicant_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGRequestPlanFindApplicant: public SWGObject {
public:
    SWGRequestPlanFindApplicant();
    SWGRequestPlanFindApplicant(QString* json);
    virtual ~SWGRequestPlanFindApplicant();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGRequestPlanFindApplicant* fromJson(QString &jsonString);

    qint32 getAge();
    void setAge(qint32 age);

private:
    qint32 age;
};

} /* namespace Swagger */

#endif /* SWGRequestPlanFindApplicant_H_ */
