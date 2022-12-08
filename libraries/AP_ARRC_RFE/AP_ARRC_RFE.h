#include <AP_Common/AP_Common.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_Vehicle/AP_Vehicle.h>
#include <GCS_MAVLink/GCS_MAVLink.h>

#define ARRC_RPI_SEARCH_MS 60000

class AP_ARRC_RFE {
public:
    AP_ARRC_RFE(void);
    ~AP_ARRC_RFE(void){}

    void init(uint16_t dfreq);

    // search for onboard computer in GCS_MAVLink routing table
    void find_RPi();

    // mavlink message handler
    float get_pwr_c(void) { return _pwr_c; }
    float get_pwr_x(void) { return _pwr_x; }
    float get_aux_1(void) { return _aux_1; }
    float get_aux_2(void) { return _aux_2; }
    float get_aux_3(void) { return _aux_3; }
    float get_freq(void) { return _freq; }
    uint64_t get_timestamp(void) { return _timestamp_us; }
    void handle_message(const mavlink_message_t &msg);

private:
    bool _initialised;
    uint8_t _sysid;                 // sysid of onboard computer
    uint8_t _compid;                // component id of onboard computer
    mavlink_channel_t _chan;        // mavlink channel used to communicate with onboard computer
    uint64_t _timestamp_us;         // time when the sample was collected (since boot)
    float _pwr_c;                   // Power measured by the RFExplorer (dBm)
    float _pwr_x;                   // Power measured by the RFExplorer (dBm)
    float _aux_1;                   // Aux 1
    float _aux_2;                   // Aux 2
    float _aux_3;                   // Aux 3
    float _freq;                    // Frequency at which the power was measured
    uint16_t _dfreq;                 // Desire frequency to sample
};