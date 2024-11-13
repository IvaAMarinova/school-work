import StarRating from "./star-rating";

interface ProductCardProps {
    badge?: string;
    award?: string;
    image: string;
    usage: string;
    name: string;
    description: string;
    reviews: number;
    rating: number;
    price?: string;
}

function ProductCard({
    badge,
    award,
    image,
    usage,
    name,
    description,
    reviews,
    rating,
    price
}: ProductCardProps) {
    return (
        <div className="max-w-xs mx-auto items-center p-6 rounded-lg">
            <div className="flex items-start justify-between relative">
                <div className="flex flex-col items-start">
                    {award && (
                        <img
                            src={award}
                            alt="Award"
                            className="w-14 h-auto mb-2 object-contain"
                        />
                    )}
                    {badge === "IMPROVED FORMULA" && (
                        <span className="bg-[#debaa7] text-xs text-white font-bold px-2 py-1 rounded-md mb-2">
                            IMPROVED <br /> FORMULA
                        </span>
                    )}
                    {badge === "NEW" && (
                        <span className="bg-[#debaa7] text-xs text-white font-bold px-2 py-1 rounded-md mb-2">
                            NEW
                        </span>
                    )}
                </div>

                <div className="flex justify-center flex-1">
                    <img
                        src={image}
                        alt={name}
                        className="h-60 object-contain"
                    />
                </div>
            </div>

            <h3 className="text-2xl text-center mt-4 text-[#816c65]">{usage}</h3>
            <h2 className="text-lg text-center text-[#816c65]">{name}</h2>
            <StarRating rating={rating} reviews={reviews} />
            <p className="text-center text-[#816c65] text-sm mb-4">{description}</p>

            <div className="flex flex-col items-center justify-between">
                <span className="text-2xl text-[#816c65] mb-2">{price} лв.</span>
                <div className="w-full py-2 bg-[#816c65] text-center text-white cursor-pointer hover:bg-[#daa48a]">
                    Добави
                </div>
            </div>
        </div>

    );
}

export default ProductCard;
