/*
 * SWGDrugSearchResponse.h
 * 
 * 
 */

#ifndef SWGDrugSearchResponse_H_
#define SWGDrugSearchResponse_H_

#include <QJsonObject>


#include "SWGDrug.h"
#include "SWGDrugPackage.h"
#include "SWGMeta.h"
#include <QList>

#include "SWGObject.h"


namespace Swagger {

class SWGDrugSearchResponse: public SWGObject {
public:
    SWGDrugSearchResponse();
    SWGDrugSearchResponse(QString* json);
    virtual ~SWGDrugSearchResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGDrugSearchResponse* fromJson(QString &jsonString);

    SWGMeta* getMeta();
    void setMeta(SWGMeta* meta);
QList<SWGDrug*>* getDrugs();
    void setDrugs(QList<SWGDrug*>* drugs);
QList<SWGDrugPackage*>* getDrugPackages();
    void setDrugPackages(QList<SWGDrugPackage*>* drug_packages);

private:
    SWGMeta* meta;
QList<SWGDrug*>* drugs;
QList<SWGDrugPackage*>* drug_packages;
};

} /* namespace Swagger */

#endif /* SWGDrugSearchResponse_H_ */
