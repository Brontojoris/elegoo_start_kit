/*
DS3231.h - Header file for the DS3231 Real-Time Clock

Version: 1.0.1
(c) 2014 Korneliusz Jarzebski
www.jarzebski.pl

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DS3231_h
#define DS3231_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define DS3231_ADDRESS              (0x68)

#define DS3231_REG_TIME             (0x00)
#define DS3231_REG_ALARM_1          (0x07)
#define DS3231_REG_ALARM_2          (0x0B)
#define DS3231_REG_CONTROL          (0x0E)
#define DS3231_REG_STATUS           (0x0F)
#define DS3231_REG_TEMPERATURE      (0x11)

#ifndef RTCDATETIME_STRUCT_H
#define RTCDATETIME_STRUCT_H
struct RTCDateTime
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t dayOfWeek;
    uint32_t unixtime;
};

struct RTCAlarmTime
{
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};
#endif

typedef enum
{
    DS3231_1HZ          = 0x00,
    DS3231_4096HZ       = 0x01,
    DS3231_8192HZ       = 0x02,
    DS3231_32768HZ      = 0x03
} DS3231_sqw_t;

typedef enum
{
    DS3231_EVERY_SECOND   = 0b00001111,
    DS3231_MATCH_S        = 0b00001110,
    DS3231_MATCH_M_S      = 0b00001100,
    DS3231_MATCH_H_M_S    = 0b00001000,
    DS3231_MATCH_DT_H_M_S = 0b00000000,
    DS3231_MATCH_DY_H_M_S = 0b00010000
} DS3231_alarm1_t;

typedef enum
{
    DS3231_EVERY_MINUTE   = 0b00001110,
    DS3231_MATCH_M        = 0b00001100,
    DS3231_MATCH_H_M      = 0b00001000,
    DS3231_MATCH_DT_H_M   = 0b00000000,
    DS3231_MATCH_DY_H_M   = 0b00010000
} DS3231_alarm2_t;

class DS3231
{
    public:

	bool begin(void);

	static void setDateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);
	static void setDateTime(uint32_t t);
	void setDateTime(const char* date, const char* time);
	RTCDateTime getDateTime(void);
	static uint8_t isReady(void);

	static DS3231_sqw_t getOutput(void);
	static void setOutput(DS3231_sqw_t mode);
	static void enableOutput(bool enabled);
	static bool isOutput(void);
	static void enable32kHz(bool enabled);
	static bool is32kHz(void);

	static void forceConversion(void);
	static float readTemperature(void);

	static void setAlarm1(uint8_t dydw, uint8_t hour, uint8_t minute, uint8_t second, DS3231_alarm1_t mode, bool armed = true);
	static RTCAlarmTime getAlarm1(void);
	static DS3231_alarm1_t getAlarmType1(void);
	static bool isAlarm1(bool clear = true);
	static void armAlarm1(bool armed);
	static bool isArmed1(void);
	static void clearAlarm1(void);

	static void setAlarm2(uint8_t dydw, uint8_t hour, uint8_t minute, DS3231_alarm2_t mode, bool armed = true);
	static RTCAlarmTime getAlarm2(void);
	static DS3231_alarm2_t getAlarmType2(void);
	static bool isAlarm2(bool clear = true);
	static void armAlarm2(bool armed);
	static bool isArmed2(void);
	static void clearAlarm2(void);

	static void setBattery(bool timeBattery, bool squareBattery);

	static char* dateFormat(const char* dateFormat, RTCDateTime dt);
	static char* dateFormat(const char* dateFormat, RTCAlarmTime dt);

    private:
	RTCDateTime t;

	static const char *strDayOfWeek(uint8_t dayOfWeek);
	static const char *strMonth(uint8_t month);
	static const char *strAmPm(uint8_t hour, bool uppercase);
	static const char *strDaySufix(uint8_t day);

	static uint8_t hour12(uint8_t hour24);
	static uint8_t bcd2dec(uint8_t bcd);
	static uint8_t dec2bcd(uint8_t dec);

	static long time2long(uint16_t days, uint8_t hours, uint8_t minutes, uint8_t seconds);
	static uint16_t date2days(uint16_t year, uint8_t month, uint8_t day);
	static uint8_t daysInMonth(uint16_t year, uint8_t month);
	static uint16_t dayInYear(uint16_t year, uint8_t month, uint8_t day);
	static bool isLeapYear(uint16_t year);
	static uint8_t dow(uint16_t y, uint8_t m, uint8_t d);

	uint32_t unixtime(void) const;
	static uint8_t conv2d(const char* p);

	static void writeRegister8(uint8_t reg, uint8_t value);
	static uint8_t readRegister8(uint8_t reg);
};

#endif