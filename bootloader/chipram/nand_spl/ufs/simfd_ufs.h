#ifndef __SIMFD_UFS_H__
#define __SIMFD_UFS_H__

/* UFSHCI Registers */
enum {
	REG_CONTROLLER_CAPABILITIES		= 0x00,
	REG_UFS_VERSION				= 0x08,
	REG_CONTROLLER_DEV_ID			= 0x10,
	REG_CONTROLLER_PROD_ID			= 0x14,
	REG_INTERRUPT_STATUS			= 0x20,
	REG_INTERRUPT_ENABLE			= 0x24,
	REG_CONTROLLER_STATUS			= 0x30,
	REG_CONTROLLER_ENABLE			= 0x34,
	REG_UIC_ERROR_CODE_PHY_ADAPTER_LAYER	= 0x38,
	REG_UIC_ERROR_CODE_DATA_LINK_LAYER	= 0x3C,
	REG_UIC_ERROR_CODE_NETWORK_LAYER	= 0x40,
	REG_UIC_ERROR_CODE_TRANSPORT_LAYER	= 0x44,
	REG_UIC_ERROR_CODE_DME			= 0x48,
	REG_UTP_TRANSFER_REQ_INT_AGG_CONTROL	= 0x4C,
	REG_UTP_TRANSFER_REQ_LIST_BASE_L	= 0x50,
	REG_UTP_TRANSFER_REQ_LIST_BASE_H	= 0x54,
	REG_UTP_TRANSFER_REQ_DOOR_BELL		= 0x58,
	REG_UTP_TRANSFER_REQ_LIST_CLEAR		= 0x5C,
	REG_UTP_TRANSFER_REQ_LIST_RUN_STOP	= 0x60,
	REG_UTP_TASK_REQ_LIST_BASE_L		= 0x70,
	REG_UTP_TASK_REQ_LIST_BASE_H		= 0x74,
	REG_UTP_TASK_REQ_DOOR_BELL		= 0x78,
	REG_UTP_TASK_REQ_LIST_CLEAR		= 0x7C,
	REG_UTP_TASK_REQ_LIST_RUN_STOP		= 0x80,
	REG_UIC_COMMAND				= 0x90,
	REG_UIC_COMMAND_ARG_1			= 0x94,
	REG_UIC_COMMAND_ARG_2			= 0x98,
	REG_UIC_COMMAND_ARG_3			= 0x9C,
	REG_UFS_OCPTHRTL                                    = 0xC0,
	REG_UFS_HCLKDIV                                        = 0xFC,
};

/* UTP Transfer Request Command Type (CT) */
enum {
	UPIU_COMMAND_SET_TYPE_SCSI	= 0x0,
	UPIU_COMMAND_SET_TYPE_UFS	= 0x1,
	UPIU_COMMAND_SET_TYPE_QUERY	= 0x2,
};

enum {
	UPIU_TRANSACTION_NOP_OUT	= 0x00,
	UPIU_TRANSACTION_COMMAND	= 0x01,
	UPIU_TRANSACTION_DATA_OUT	= 0x02,
	UPIU_TRANSACTION_TASK_REQ	= 0x04,
	UPIU_TRANSACTION_QUERY_REQ	= 0x16,
};

enum {
	UPIU_CMD_FLAGS_NONE	= 0x00,
	UPIU_CMD_FLAGS_WRITE	= 0x20,
	UPIU_CMD_FLAGS_READ	= 0x40,
};

struct ufs_pa_layer_attr {
	uint32_t gear_rx;
	uint32_t gear_tx;
	uint32_t lane_rx;
	uint32_t lane_tx;
	uint32_t pwr_rx;
	uint32_t pwr_tx;
	uint32_t hs_rate;
};

/* PA power modes */
enum {
	FAST_MODE	= 1,
	SLOW_MODE	= 2,
	FASTAUTO_MODE	= 4,
	SLOWAUTO_MODE	= 5,
	UNCHANGED	= 7,
};

/* PA TX/RX Frequency Series */
enum {
	PA_HS_MODE_A	= 1,
	PA_HS_MODE_B	= 2,
};

enum ufs_hs_gear_tag {
	UFS_HS_DONT_CHANGE,	/* Don't change Gear */
	UFS_HS_G1,		/* HS Gear 1 (default for reset) */
	UFS_HS_G2,		/* HS Gear 2 */
	UFS_HS_G3,		/* HS Gear 3 */
};

#define PA_ACTIVETXDATALANES	0x1560
#define PA_CONNECTEDTXDATALANES	0x1561
#define PA_TXGEAR		0x1568
#define PA_TXTERMINATION	0x1569
#define PA_HSSERIES		0x156A
#define PA_PWRMODE		0x1571
#define PA_ACTIVERXDATALANES	0x1580
#define PA_CONNECTEDRXDATALANES	0x1581
#define PA_RXGEAR		0x1583
#define PA_RXTERMINATION	0x1584
#define PA_MAXRXPWMGEAR		0x1586
#define PA_MAXRXHSGEAR		0x1587

#define DW_UFS_IS_UPMS   UFS_BIT(4)

/* UIC Commands */
enum uic_cmd_dme {
	UIC_CMD_DME_GET			= 0x01,
	UIC_CMD_DME_SET			= 0x02,
	UIC_CMD_DME_PEER_GET		= 0x03,
	UIC_CMD_DME_PEER_SET		= 0x04,
	UIC_CMD_DME_POWERON		= 0x10,
	UIC_CMD_DME_POWEROFF		= 0x11,
	UIC_CMD_DME_ENABLE		= 0x12,
	UIC_CMD_DME_RESET		= 0x14,
	UIC_CMD_DME_END_PT_RST		= 0x15,
	UIC_CMD_DME_LINK_STARTUP	= 0x16,
	UIC_CMD_DME_HIBER_ENTER		= 0x17,
	UIC_CMD_DME_HIBER_EXIT		= 0x18,
	UIC_CMD_DME_TEST_MODE		= 0x1A,
};

/* UIC Config result code / Generic error code */
enum {
	UIC_CMD_RESULT_SUCCESS			= 0x00,
	UIC_CMD_RESULT_INVALID_ATTR		= 0x01,
	UIC_CMD_RESULT_FAILURE			= 0x01,
	UIC_CMD_RESULT_INVALID_ATTR_VALUE	= 0x02,
	UIC_CMD_RESULT_READ_ONLY_ATTR		= 0x03,
	UIC_CMD_RESULT_WRITE_ONLY_ATTR		= 0x04,
	UIC_CMD_RESULT_BAD_INDEX		= 0x05,
	UIC_CMD_RESULT_LOCKED_ATTR		= 0x06,
	UIC_CMD_RESULT_BAD_TEST_FEATURE_INDEX	= 0x07,
	UIC_CMD_RESULT_PEER_COMM_FAILURE	= 0x08,
	UIC_CMD_RESULT_BUSY			= 0x09,
	UIC_CMD_RESULT_DME_FAILURE		= 0x0A,
};

/* Overall command status values */
enum {
	OCS_SUCCESS			= 0x0,
	OCS_INVALID_CMD_TABLE_ATTR	= 0x1,
	OCS_INVALID_PRDT_ATTR		= 0x2,
	OCS_MISMATCH_DATA_BUF_SIZE	= 0x3,
	OCS_MISMATCH_RESP_UPIU_SIZE	= 0x4,
	OCS_PEER_COMM_FAILURE		= 0x5,
	OCS_ABORTED			= 0x6,
	OCS_FATAL_ERROR			= 0x7,
	OCS_INVALID_COMMAND_STATUS	= 0x0F,
	MASK_OCS			= 0x0F,
};

#define DME_LINKSTARTUP_RETRIES 3
#define NOP_OUT_RETRIES 20

#define QUERY_REQ_RETRIES 10
#define QUERY_REQ_TIMEOUT 30 /* msec */

#define MAX_PRDT_BUFFER_SIZE (256*1024)

#define LOWER_32_BITS(x)       ((u32)((x)    &  0xFFFFFFFFUL))
#define UPPER_32_BITS(x)       ((u32)((x)    >> 32))
//#define LOWER_32_BITS(x)       (u32)((sizeof(x)==4)? (x):(u64)(x)   &  0xFFFFFFFFUL)
//#define UPPER_32_BITS(x)       (u32)((sizeof(x)==4)? (x):(u64)(x)   >> 32)


#define UFS_BIT(x)	(1L << (x))

#define UTP_TRANSFER_REQ_COMPL			UFS_BIT(0)
#define UIC_DME_END_PT_RESET			UFS_BIT(1)
#define UIC_ERROR				UFS_BIT(2)
#define UIC_TEST_MODE				UFS_BIT(3)
#define UIC_POWER_MODE				UFS_BIT(4)
#define UIC_HIBERNATE_EXIT			UFS_BIT(5)
#define UIC_HIBERNATE_ENTER			UFS_BIT(6)
#define UIC_LINK_LOST				UFS_BIT(7)
#define UIC_LINK_STARTUP			UFS_BIT(8)
#define UTP_TASK_REQ_COMPL			UFS_BIT(9)
#define UIC_COMMAND_COMPL			UFS_BIT(10)
#define DEVICE_FATAL_ERROR			UFS_BIT(11)
#define CONTROLLER_FATAL_ERROR			UFS_BIT(16)
#define SYSTEM_BUS_FATAL_ERROR			UFS_BIT(17)


/* HCS - Host Controller Status 30h */
#define DEVICE_PRESENT				UFS_BIT(0)
#define UTP_TRANSFER_REQ_LIST_READY		UFS_BIT(1)
#define UTP_TASK_REQ_LIST_READY			UFS_BIT(2)
#define UIC_COMMAND_READY			UFS_BIT(3)
#define HOST_ERROR_INDICATOR			UFS_BIT(4)
#define DEVICE_ERROR_INDICATOR			UFS_BIT(5)
#define UIC_POWER_MODE_CHANGE_REQ_STATUS_MASK	UFS_MASK(0x7, 8)

/* HCE - Host Controller Enable 34h */
#define CONTROLLER_ENABLE	UFS_BIT(0)
#define CONTROLLER_DISABLE	0x0

/* UICCMD - UIC Command */
#define COMMAND_OPCODE_MASK		0xFF
#define GEN_SELECTOR_INDEX_MASK		0xFFFF

#define RESET_LEVEL			0xFF

#define CONFIG_RESULT_CODE_MASK		0xFF
#define GENERIC_ERROR_CODE_MASK		0xFF

#define RETRY_CNT              2000


/* The command type offset of UTRD */
#define UTRD_COMMAND_TYPE_OFFSET	28

#define ALIGNED_UPIU_SIZE	512
#define TM_UPIU_SIZE_DW		8

/* Max size per trans is limited at 16 * 256K */
#define MAX_PRDT_ENTRY		16

#define LOGICAL_BLK_SIZE       4096

#define MAX_CDB_SIZE	16

#endif /* __SIMFD_UFS_H__ */
