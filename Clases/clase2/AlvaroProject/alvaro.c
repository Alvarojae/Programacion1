
int numeroMayor (int dato,int dato1,int dato2)
{

    int datoMayor;
    if(dato>=dato1 && dato>=dato2)
    {
        datoMayor=dato;
    }else
    {
        if(dato1>=dato && dato1>=dato2)
    {
        datoMayor=dato1;
    }else
        datoMayor=dato2;
    }

    return datoMayor;

}
