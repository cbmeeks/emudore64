 
#ifndef __MYOS__DRIVERS__ATA_H
#define __MYOS__DRIVERS__ATA_H

#include <lib/stdint.h>
#include <lib/stdio.h>
#include <hardwarecommunication/interrupts.h>
#include <hardwarecommunication/port.h>

#define _ATA_FIRST		0x1F0	// interrupt 14
#define _ATA_SECOND		0x170	// interrupt 15
#define	_ATA_THIRD		0x1E8
#define _ATA_FOURTH		0x168

namespace myos
{
    namespace drivers
    {
        
        class AdvancedTechnologyAttachment
        {
        protected:
            bool master;
            hardwarecommunication::Port16Bit dataPort;
            hardwarecommunication::Port8Bit errorPort;
            hardwarecommunication::Port8Bit sectorCountPort;
            hardwarecommunication::Port8Bit lbaLowPort;
            hardwarecommunication::Port8Bit lbaMidPort;
            hardwarecommunication::Port8Bit lbaHiPort;
            hardwarecommunication::Port8Bit devicePort;
            hardwarecommunication::Port8Bit commandPort;
            hardwarecommunication::Port8Bit controlPort;
        public:
            
            AdvancedTechnologyAttachment(bool master, uint16_t portBase);
            ~AdvancedTechnologyAttachment();
            
            void Identify();
            void Read28(uint32_t sectorNum, uint8_t* sector, int count = 512);
            void Write28(uint32_t sectorNum, uint8_t* data, uint32_t count);
            void Flush();
            
            
        };
        
    }
}

#endif
