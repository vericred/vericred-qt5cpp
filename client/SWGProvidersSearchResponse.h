/*
 * SWGProvidersSearchResponse.h
 * 
 * 
 */

#ifndef SWGProvidersSearchResponse_H_
#define SWGProvidersSearchResponse_H_

#include <QJsonObject>


#include "SWGMeta.h"
#include "SWGProvider.h"
#include "SWGState.h"
#include <QList>

#include "SWGObject.h"


namespace Swagger {

class SWGProvidersSearchResponse: public SWGObject {
public:
    SWGProvidersSearchResponse();
    SWGProvidersSearchResponse(QString* json);
    virtual ~SWGProvidersSearchResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGProvidersSearchResponse* fromJson(QString &jsonString);

    SWGMeta* getMeta();
    void setMeta(SWGMeta* meta);
QList<SWGProvider*>* getProviders();
    void setProviders(QList<SWGProvider*>* providers);
QList<SWGState*>* getStates();
    void setStates(QList<SWGState*>* states);

private:
    SWGMeta* meta;
QList<SWGProvider*>* providers;
QList<SWGState*>* states;
};

} /* namespace Swagger */

#endif /* SWGProvidersSearchResponse_H_ */
