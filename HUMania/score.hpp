class Score{
public:
    Score() ;


    //do op overlloading for increments/decrements of 10
    Score& operator++(){
        ScoreCount+=10 ;
        return *this; 
    }

    Score& operator--(){
        ScoreCount-=10 ;
        return *this; 
    }



    int getScore()const{
        return ScoreCount ;
    }
private:
    int ScoreCount = 0;


}; 