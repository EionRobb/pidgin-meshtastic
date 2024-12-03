/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_MESHTASTIC_REMOTE_HARDWARE_PB_H_INCLUDED
#define PB_MESHTASTIC_REMOTE_HARDWARE_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* TODO: REPLACE */
typedef enum _meshtastic_HardwareMessage_Type {
    /* Unset/unused */
    meshtastic_HardwareMessage_Type_UNSET = 0,
    /* Set gpio gpios based on gpio_mask/gpio_value */
    meshtastic_HardwareMessage_Type_WRITE_GPIOS = 1,
    /* We are now interested in watching the gpio_mask gpios.
 If the selected gpios change, please broadcast GPIOS_CHANGED.
 Will implicitly change the gpios requested to be INPUT gpios. */
    meshtastic_HardwareMessage_Type_WATCH_GPIOS = 2,
    /* The gpios listed in gpio_mask have changed, the new values are listed in gpio_value */
    meshtastic_HardwareMessage_Type_GPIOS_CHANGED = 3,
    /* Read the gpios specified in gpio_mask, send back a READ_GPIOS_REPLY reply with gpio_value populated */
    meshtastic_HardwareMessage_Type_READ_GPIOS = 4,
    /* A reply to READ_GPIOS. gpio_mask and gpio_value will be populated */
    meshtastic_HardwareMessage_Type_READ_GPIOS_REPLY = 5
} meshtastic_HardwareMessage_Type;

/* Struct definitions */
/* An example app to show off the module system. This message is used for
 REMOTE_HARDWARE_APP PortNums.
 Also provides easy remote access to any GPIO.
 In the future other remote hardware operations can be added based on user interest
 (i.e. serial output, spi/i2c input/output).
 FIXME - currently this feature is turned on by default which is dangerous
 because no security yet (beyond the channel mechanism).
 It should be off by default and then protected based on some TBD mechanism
 (a special channel once multichannel support is included?) */
typedef struct _meshtastic_HardwareMessage {
    /* What type of HardwareMessage is this? */
    meshtastic_HardwareMessage_Type type;
    /* What gpios are we changing. Not used for all MessageTypes, see MessageType for details */
    uint64_t gpio_mask;
    /* For gpios that were listed in gpio_mask as valid, what are the signal levels for those gpios.
 Not used for all MessageTypes, see MessageType for details */
    uint64_t gpio_value;
} meshtastic_HardwareMessage;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _meshtastic_HardwareMessage_Type_MIN meshtastic_HardwareMessage_Type_UNSET
#define _meshtastic_HardwareMessage_Type_MAX meshtastic_HardwareMessage_Type_READ_GPIOS_REPLY
#define _meshtastic_HardwareMessage_Type_ARRAYSIZE ((meshtastic_HardwareMessage_Type)(meshtastic_HardwareMessage_Type_READ_GPIOS_REPLY+1))

#define meshtastic_HardwareMessage_type_ENUMTYPE meshtastic_HardwareMessage_Type


/* Initializer values for message structs */
#define meshtastic_HardwareMessage_init_default  {_meshtastic_HardwareMessage_Type_MIN, 0, 0}
#define meshtastic_HardwareMessage_init_zero     {_meshtastic_HardwareMessage_Type_MIN, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define meshtastic_HardwareMessage_type_tag      1
#define meshtastic_HardwareMessage_gpio_mask_tag 2
#define meshtastic_HardwareMessage_gpio_value_tag 3

/* Struct field encoding specification for nanopb */
#define meshtastic_HardwareMessage_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    type,              1) \
X(a, STATIC,   SINGULAR, UINT64,   gpio_mask,         2) \
X(a, STATIC,   SINGULAR, UINT64,   gpio_value,        3)
#define meshtastic_HardwareMessage_CALLBACK NULL
#define meshtastic_HardwareMessage_DEFAULT NULL

extern const pb_msgdesc_t meshtastic_HardwareMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define meshtastic_HardwareMessage_fields &meshtastic_HardwareMessage_msg

/* Maximum encoded size of messages (where known) */
#define MESHTASTIC_REMOTE_HARDWARE_PB_H_MAX_SIZE meshtastic_HardwareMessage_size
#define meshtastic_HardwareMessage_size          24

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
