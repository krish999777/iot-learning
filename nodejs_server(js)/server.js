import express from 'express'

const app=express()

app.post('/input',(req,res)=>{
    console.log("clicked")
    res.status(200).json({message:"Success"})
})

const PORT=8000;
app.listen(PORT,'0.0.0.0',()=>console.log(`Server listening on port ${PORT}`))