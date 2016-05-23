/*
 * SWGPlanSearchResponse.h
 * 
 * 
 */

#ifndef SWGPlanSearchResponse_H_
#define SWGPlanSearchResponse_H_

#include <QJsonObject>


#include "SWGDrug.h"
#include "SWGMeta.h"
#include "SWGPlan.h"
#include <QList>

#include "SWGObject.h"


namespace Swagger {

class SWGPlanSearchResponse: public SWGObject {
public:
    SWGPlanSearchResponse();
    SWGPlanSearchResponse(QString* json);
    virtual ~SWGPlanSearchResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGPlanSearchResponse* fromJson(QString &jsonString);

    SWGMeta* getMeta();
    void setMeta(SWGMeta* meta);
QList<SWGPlan*>* getPlans();
    void setPlans(QList<SWGPlan*>* plans);
QList<SWGDrug*>* getCoverages();
    void setCoverages(QList<SWGDrug*>* coverages);

private:
    SWGMeta* meta;
QList<SWGPlan*>* plans;
QList<SWGDrug*>* coverages;
};

} /* namespace Swagger */

#endif /* SWGPlanSearchResponse_H_ */
