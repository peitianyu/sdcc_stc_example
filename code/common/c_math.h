#ifndef __C_MATH_H__
#define __C_MATH_H__

#define float2hex(float_dat) (unsigned char *)&float_dat;

// !注意: hex的size应该是4
#define hex2float(hex) *(float *)hex

#endif // __C_MATH_H__