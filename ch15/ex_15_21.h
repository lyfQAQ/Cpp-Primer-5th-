/***ex_15_21***/
#ifndef EX_15_21_H
#define EX_15_21_H

static const float PI = 3.14159f;

class Shape
{
public:
    virtual const char* shapename() = 0;
    virtual void resizeByPercentage(float pct) = 0;
    virtual ~Shape() {}
};

class Shape_2D : public Shape
{
public:
    Shape_2D() = default;
    Shape_2D(float x, float y) : x_(x), y_(y) {}
    virtual ~Shape_2D() {}

    virtual float area() const = 0;
    virtual float diameter() const = 0;
    virtual float circumference() const = 0;

protected:
    float x_ = 0.f;
    float y_ = 0.f;
};

class Shape_3D : public Shape
{
public:
    Shape_3D() = default;
    Shape_3D(float x, float y, float z) : x_(x), y_(y), z_(x) {}
    virtual ~Shape_3D() {}
    virtual float volume() const = 0;

protected:
    float x_ = 0.f;
    float y_ = 0.f;
    float z_ = 0.f;
};

class Circle : public Shape_2D
{
public:
    Circle() = default;
    explicit Circle(float radius) : radius_(radius) {}
    Circle(float center_x, float center_y, float radius) : Shape_2D(center_x, center_y), radius_(radius) {}
    virtual ~Circle() {}

    virtual float area() const override
    {
        return PI * radius_ * radius_;
    }
    virtual float diameter() const override
    {
        return 2 * radius_;
    }
    virtual float circumference() const override
    {
        return 2 * PI * radius_;
    }
    virtual const char* shapename() override
    {
        return "Circle";
    }
    virtual void resizeByPercentage(float pct) override
    {
        radius_ *= pct;
    }

protected:
    float radius_ = 1.f;
};

class Cone : public Shape_3D
{
public:
	Cone() = default;
	Cone(float radius, float height) : radius_(radius), height_(height) {}
	Cone(float center_x, float center_y, float center_z, float radius, float height) : Shape_3D(center_x, center_y, center_z), radius_(radius), height_(height) {}
	virtual ~Cone() {}

	virtual const char* shapename() override
	{
		return "Cone";
	}
	virtual void resizeByPercentage(float pct) override
	{
		radius_ *= pct;
		height_ *= pct;
	}
	virtual float volume() const override
	{
		return PI * radius_ * radius_ * height_ / 3;
	}

protected:
	float radius_ = 1.f;
	float height_ = 1.f;
};
#endif
