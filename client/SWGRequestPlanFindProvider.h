/*
 * SWGRequestPlanFindProvider.h
 * 
 * 
 */

#ifndef SWGRequestPlanFindProvider_H_
#define SWGRequestPlanFindProvider_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGRequestPlanFindProvider: public SWGObject {
public:
    SWGRequestPlanFindProvider();
    SWGRequestPlanFindProvider(QString* json);
    virtual ~SWGRequestPlanFindProvider();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGRequestPlanFindProvider* fromJson(QString &jsonString);

    qint32 getNpi();
    void setNpi(qint32 npi);

private:
    qint32 npi;
};

} /* namespace Swagger */

#endif /* SWGRequestPlanFindProvider_H_ */
