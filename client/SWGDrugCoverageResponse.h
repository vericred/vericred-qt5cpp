/*
 * SWGDrugCoverageResponse.h
 * 
 * 
 */

#ifndef SWGDrugCoverageResponse_H_
#define SWGDrugCoverageResponse_H_

#include <QJsonObject>


#include "SWGDrug.h"
#include "SWGDrugCoverage.h"
#include "SWGDrugPackage.h"
#include "SWGMeta.h"
#include <QList>

#include "SWGObject.h"


namespace Swagger {

class SWGDrugCoverageResponse: public SWGObject {
public:
    SWGDrugCoverageResponse();
    SWGDrugCoverageResponse(QString* json);
    virtual ~SWGDrugCoverageResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGDrugCoverageResponse* fromJson(QString &jsonString);

    SWGMeta* getMeta();
    void setMeta(SWGMeta* meta);
QList<SWGDrugCoverage*>* getDrugCoverages();
    void setDrugCoverages(QList<SWGDrugCoverage*>* drug_coverages);
QList<SWGDrug*>* getDrugs();
    void setDrugs(QList<SWGDrug*>* drugs);
QList<SWGDrugPackage*>* getDrugPackages();
    void setDrugPackages(QList<SWGDrugPackage*>* drug_packages);

private:
    SWGMeta* meta;
QList<SWGDrugCoverage*>* drug_coverages;
QList<SWGDrug*>* drugs;
QList<SWGDrugPackage*>* drug_packages;
};

} /* namespace Swagger */

#endif /* SWGDrugCoverageResponse_H_ */
