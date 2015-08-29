unsigned long int idefbands(unsigned long int rd,unsigned long int rm,unsigned long int temp);
{
    unsigned long int bands[4]={0};
    if(rd>2147483648)
    {
        bands[0]=1;
    }
    if(rd=0)
    {
        bands[1]=1;
    }
    if(rd>4294967296)
    {
        bands[2]=1;
    }
    if(((rd&&rm)>=2147483648)&&((rd+rm)<2147483648))
        bands[3];
}
