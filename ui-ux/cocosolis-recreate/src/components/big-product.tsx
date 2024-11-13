import StarRating from "./star-rating";

interface BigProductCardProps {
    badge?: string;
    award?: string;
    image: string;
    name: string;
    usage: string;
    description: string;
    reviews: number;
    rating: number;
    price?: string;
}

function BigProductCard({
    image,
    name,
    usage,
    description,
    reviews,
    rating,
    price
}: BigProductCardProps) {
    return (
        <div className="max-w-md mx-auto items-start p-12 relative">            
            <div className="flex justify-center">
                <img src={image} alt={name} className="h-96" />
            </div>

            <h3 className="text-2xl text-center mt-4 text-[#816c65]">{usage}</h3>
            <h2 className="text-lg text-center text-[#816c65]">{name}</h2>
            <StarRating rating={rating} reviews={reviews} />
            <p className="text-center text-[#816c65] text-base mb-6">{description}</p>

            <div className="flex flex-col items-center justify-between mt-6">
                <span className="text-3xl text-[#816c65] mb-4">{price} лв.</span>
                <button className="px-8 py-3 bg-[#816c65] text-white text-lg hover:bg-[#daa48a]">
                    Добави
                </button>
            </div>
        </div>
    );
}

export default BigProductCard;
