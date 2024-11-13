import { StarSolid } from "@mynaui/icons-react";

interface StarRatingProps {
    rating: number;
    reviews?: number;
}  

function StarRating({ rating, reviews }: StarRatingProps) {
    return (
        <div className="flex items-center justify-center space-x-1">
            {[...Array(5)].map((_, index) => (
            <StarSolid
                key={index}
                className={`h-4 w-4 ${index < rating ? "text-[#daa48a]" : "text-gray-300"}`}
            />
                ))}
        <span className="text-xs text-[#816c65] ml-2">{reviews} мнения</span>
        </div>
    );
};

export default StarRating;
