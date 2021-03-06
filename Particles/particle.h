#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsItem>
#include <QObject>
#include <QVector2D>
#include <QGraphicsPixmapItem>
class Level1;

class Particle : public QGraphicsPixmapItem
{

public:
    Particle(QPixmap* pixmap, QPointF& origin, Level1 *scene);
    ~Particle();
    void update();

    void advance(int phase) override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    bool is_finished();
    void applyForce(QVector2D& force);
    void setPosition(QPointF pos_);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    QVector2D pos;
    QVector2D vel;
    QVector2D acc;
    float lifespan;
    float d; //delta
    QRectF rect;
    QPointF* m_origin;
    QPixmap *m_pixmap = nullptr;
    Level1 *m_scene = nullptr;
};
#endif // PARTICLE_H
