#pragma once

struct XRCORE_API SPPInfo
{
	struct SColor
	{
		float r, g, b;
		SColor() {}
		SColor(float _r, float _g, float _b) : r(_r), g(_g), b(_b) { }
		inline operator u32()
		{
			int _r = clampr(iFloor(r * 255.f + .5f), 0, 255);
			int _g = clampr(iFloor(g * 255.f + .5f), 0, 255);
			int _b = clampr(iFloor(b * 255.f + .5f), 0, 255);
			return color_rgba(_r, _g, _b, 0);
		}

		inline operator const Fvector&()
		{
			return *((Fvector*)this);
		}

		inline SColor& operator+=(const SColor& ppi)
		{
			r += ppi.r;
			g += ppi.g;
			b += ppi.b;
			return *this;
		}
		inline SColor& operator-=(const SColor& ppi)
		{
			r -= ppi.r;
			g -= ppi.g;
			b -= ppi.b;
			return *this;
		}
		inline SColor& set(float _r, float _g, float _b)
		{
			r = _r;
			g = _g;
			b = _b;
			return *this;
		}
	};

	float blur, gray;
	struct SDuality
	{
		float h, v;
		SDuality() {}
		SDuality(float _h, float _v) : h(_h), v(_v) { }

		inline SDuality& set(float _h, float _v)
		{
			h = _h;
			v = _v;
			return *this;
		}
	} duality;

	struct SNoise
	{
		float intensity, grain;
		float fps;
		SNoise() {}
		SNoise(float _i, float _g, float _f)
			: intensity(_i)
			, grain(_g)
			, fps(_f)
		{
		}
		inline SNoise& set(float _i, float _g, float _f)
		{
			intensity = _i;
			grain = _g;
			fps = _f;
			return *this;
		}
	} noise;

	SColor color_base;
	SColor color_gray;
	SColor color_add;
	float cm_influence;
	float cm_interpolate;
	shared_str cm_tex1;
	shared_str cm_tex2;

	SPPInfo& add(const SPPInfo& ppi);
	SPPInfo& sub(const SPPInfo& ppi);
	void normalize();
	SPPInfo();
	SPPInfo& lerp(const SPPInfo& def, const SPPInfo& to, float factor);
	void validate(LPCSTR str);
};

XRCORE_API extern SPPInfo pp_identity;
XRCORE_API extern SPPInfo pp_zero;