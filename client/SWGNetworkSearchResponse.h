/*
 * SWGNetworkSearchResponse.h
 * 
 * 
 */

#ifndef SWGNetworkSearchResponse_H_
#define SWGNetworkSearchResponse_H_

#include <QJsonObject>


#include "SWGMeta.h"
#include "SWGNetwork.h"
#include <QList>

#include "SWGObject.h"


namespace Swagger {

class SWGNetworkSearchResponse: public SWGObject {
public:
    SWGNetworkSearchResponse();
    SWGNetworkSearchResponse(QString* json);
    virtual ~SWGNetworkSearchResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGNetworkSearchResponse* fromJson(QString &jsonString);

    SWGMeta* getMeta();
    void setMeta(SWGMeta* meta);
QList<SWGNetwork*>* getNetworks();
    void setNetworks(QList<SWGNetwork*>* networks);

private:
    SWGMeta* meta;
QList<SWGNetwork*>* networks;
};

} /* namespace Swagger */

#endif /* SWGNetworkSearchResponse_H_ */
