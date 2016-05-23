/*
 * SWGRequestProvidersSearch.h
 * 
 * 
 */

#ifndef SWGRequestProvidersSearch_H_
#define SWGRequestProvidersSearch_H_

#include <QJsonObject>


#include <QList>
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGRequestProvidersSearch: public SWGObject {
public:
    SWGRequestProvidersSearch();
    SWGRequestProvidersSearch(QString* json);
    virtual ~SWGRequestProvidersSearch();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGRequestProvidersSearch* fromJson(QString &jsonString);

    bool getAcceptsInsurance();
    void setAcceptsInsurance(bool accepts_insurance);
QList<QString*>* getHiosIds();
    void setHiosIds(QList<QString*>* hios_ids);
qint32 getPage();
    void setPage(qint32 page);
qint32 getPerPage();
    void setPerPage(qint32 per_page);
qint32 getRadius();
    void setRadius(qint32 radius);
QString* getSearchTerm();
    void setSearchTerm(QString* search_term);
QString* getZipCode();
    void setZipCode(QString* zip_code);
QString* getType();
    void setType(QString* type);

private:
    bool accepts_insurance;
QList<QString*>* hios_ids;
qint32 page;
qint32 per_page;
qint32 radius;
QString* search_term;
QString* zip_code;
QString* type;
};

} /* namespace Swagger */

#endif /* SWGRequestProvidersSearch_H_ */
